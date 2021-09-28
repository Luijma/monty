#include "monty.h"
/**
 * main - entry point for monty interpreter
 * @argc: number of arguments passed
 * @argv: Name of file to interpret
 * Return: 1 if error, 0 on success
 */
int main(int argc, char *argv[])
{
	char line_buf[1000], **line_array;
	int line_count = 0;
	size_t line_size = 0;
	FILE *file;
	void (*func_ptr)(stack_t **, unsigned int) = NULL;
	stack_t *stack = NULL;

	global_info.err_state = 0;
	if (argc == 2)
		file = fopen(argv[1], "r");
	initial_errors(file, argc, argv);
	while (fgets(line_buf, sizeof(line_buf), file) != NULL &&
			!global_info.err_state)
	{
		line_count++;
		line_size = strlen(line_buf);
		line_buf[line_size - 1] = '\0';
		line_array = tokenizeInput(line_buf);
		global_info.node_value = line_array[1];
		global_info.command = line_array[0];
		func_ptr = selectFunction(line_array[0]);
		if (!(func_ptr))
		{
			global_info.err_state = 1;
			global_info.err_info = "unknown_instruction";
			break;
		}
		func_ptr(&stack, line_count);
	}
	if (global_info.err_state == 1)
	{
		error_handler();
		global_info.ef(line_count);
		free_stacks(stack);
		fclose(file);
		free(line_array);
		exit(EXIT_FAILURE);
	}
	free_stacks(stack);
	fclose(file);
	free(line_array);
	return (0);
}
/**
 * monty_usage_error - error handling for usage error
 * @n: line error occurred in
 */
void monty_usage_error(unsigned int n __attribute__((unused)))
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * file_error - handles the file error
 * @n: line of error
 */
void file_error(unsigned int n __attribute__((unused)))
{
	fprintf(stderr, "Error: Can't open file <%s>\n", global_info.node_value);
	exit(EXIT_FAILURE);
}
void initial_errors(FILE *file, int argc, char *argv[])
{
	if (argc != 2)
	{
		fclose(file);
		monty_usage_error(0);
	}
	global_info.node_value = argv[1];
	if (!file)
		file_error(0);
}
