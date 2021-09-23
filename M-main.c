#include "monty.h"
/**
 * main - entry point for monty interpreter
 * @argc: number of arguments passed
 * @argv: Name of file to interpret
 * Return: 1 if error, 0 on success
 */
int main(int argc, char *argv[])
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;
	FILE *file;

	if (argc != 2)
	{
		err_usage();
	}

	/* Open file in Read Only and check for error */
	file = fopen(argv[1], "r");

	if (!file)
	{
		err_file();
	}

	line_size = getline(&line_buf, &line_buf_size, file);

	while (line_size >= 0)
	{
		line_count++;

		/* replace this code with the input processing */
		process_line(line_buf, line_buf_size);

		line_size = getline(&line_buf, &line_buf_size, file);
	}

	free(line_buf);
	line_buf = NULL;
	fclose(file);

	return (0);
}
