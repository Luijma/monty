/**
 * process_line - adds commands and parameters to array
 * @line - line to be tokenized
 */
char **tokenizeInput(char *input)
{
	char *token, *temp;
	const char space = " \n\t";
	char **input_array;
	int idx = 0;

	input_array = malloc(sizeof(char *) * 3);

	if(input_array == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp = strdup(input);
	token = strtok(temp, space);

	while (token != NULL && idx < 2)
	{
		input_array[idx] = strdup(token);
		idx++;
		token = strtok(NULL, space);
	}
	input_array[idx] = NULL;
	free(temp);

	return (input_array);
}
