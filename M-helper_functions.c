#include "monty.h"
#include <stdlib.h>
#include <string.h>
/**
 * tokenizeInput - adds commands and parameters to array
 * @input: line to be tokenized
 * Return: tokenized string
 */
char **tokenizeInput(char *input)
{
	char *token, *temp;
	const char *space = " \n\t";
	char **input_array;
	int idx = 0;

	input_array = malloc(sizeof(char *) * 3);

	if (input_array == NULL)
	{
		return (NULL);
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
/**
 * selectFunction - returns a function pointer that executes commands
 * @input: input to compare to
 * Return: function pointer
 */
void (*selectFunction(char *input))(stack_t **stack, unsigned int line_number)
{
	instruction_t function[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	int idx = 0;

	while (function[idx].opcode)
	{
		if (strcmp(input, function[idx].opcode) == 0)
		{
			return (function[idx].f);
		}
		idx++;
	}

	return (function[idx].f);
}
/**
 * strdup - duplicates a string
 * @s: string to duplicate
 * Return: duplicated string
 */
char *strdup(const char *s)
{
	size_t size = strlen(s) + 1;
	char *p = malloc(size);

	if (p != NULL)
	{
		memcpy(p, s, size);
	}
	return (p);
}
/**
 * _isdigit - checks if string is digit
 * @str: string to check
 * Return: 1 if digit, 0 if not
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}
/**
 * free_stacks - frees a stack
 * @head: top of stack to free
 */
void free_stacks(stack_t *head)
{
	stack_t *curr = head;
	stack_t *next;

	if (!head)
		return;

	next = head->next;
	while (curr)
	{
		free(curr);
		curr = next;
		if (next)
			next = next->next;
	}
}
