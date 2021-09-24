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
	size_t line_size;
	FILE *file;
	void (*func_ptr)(stack_t **, unsigned int) = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error printing file\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(line_buf, sizeof(line_buf), file) != NULL)
	{
		line_count++;
		line_size = strlen(line_buf);
		line_buf[line_size - 1] = '\0';
		line_array = tokenizeInput(line_buf);
		node_value = line_array[1];

		func_ptr = selectFunction(line_array[0]);
		if (!(func_ptr))
		{
			fprintf(stderr, "pending function pointer error\n");
			fclose(file);
			exit(EXIT_FAILURE);
		}
		func_ptr(&stack, line_count);
	}
	free_stacks(stack);
	fclose(file);
	return (0);
}
