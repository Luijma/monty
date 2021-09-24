#include "monty.h"
/**
 * push - pushes an element to the stack (adds begin)
 * @stack: stack to push elemnt to
 * Return: returns pointer to the top of the stack
 */
void push(stack_t **head, unsigned int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));

	/* add code to assign argument to n */

	if (!new_node)
		return;

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
