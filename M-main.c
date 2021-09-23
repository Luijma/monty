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
	//del
	int idx = 0, idx = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	/* Open file in Read Only and check for error */
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error printing file");
		exit(EXIT_FAILURE);
	}

	line_size = getline(&line_buf, &line_buf_size, file);

	while (line_size >= 0)
	{
		line_count++;

		line_size = getline(&line_buf, &line_buf_size, file);
		line_buf[line_size -1] = '\0';
		printf("%s line count: <%i>\n", line_buf, line_count);

		line_array = tokenizeInput(line_buf);

		for(idx1 = 0; line_array[idx1] != NULL; idx1++)
		{
			printf("line_array[%i] <%s>\n", idx, line_array[idx]);
		}
	}

	free(line_buf);
	fclose(file);

	return (0);
}
