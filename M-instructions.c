#include "monty.h"
/**
 * push - pushes an element to the stack (adds begin)
 * @stack: stack to push elemnt to
 * Return: returns pointer to the top of the stack
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int n;

	new_node = malloc(sizeof(stack_t));

	/* add code to assign argument to n */

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (node_value == NULL || !isdigit(node_value))
	{
		fprintf(stderr, "L<%u>: usage: push integer/n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(node_value);

	if (!*head)
	{
		new_node->n = n;
		new_node->prev = NULL;
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		new_node->n = n;
		new_node->prev = (*head)->prev;
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}
void pall(stack_t **head, unsigned int n __attribute__((unused)))
{
	while (*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
}
