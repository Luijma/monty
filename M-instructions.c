#include "monty.h"
/**
 * push - pushes an element to the stack (adds begin)
 * @head: stack to push elemnt to
 * @line_number: line number for error
 * Return: returns pointer to the top of the stack
 */
void push(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node = NULL;
	int n;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		global_info.err_state = 1;
		global_info.err_info = "malloc_error";
		free(new_node);
		return;
	}
	if (global_info.node_value == NULL || _isdigit(global_info.node_value) == 0)
	{
		global_info.err_info = "push_error";
		global_info.err_state = 1;
		free(new_node);
		return;
	}

	n = atoi(global_info.node_value);

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
/**
 * pall - prints all stack members
 * @head: head of list
 * @n: unused number
 */
void pall(stack_t **head, unsigned int n __attribute__((unused)))
{
	stack_t *temp = *head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - prints top of stack
 * @head: head of stack to print
 * @n: line number for error
 */
void pint(stack_t **head, unsigned int n __attribute__((unused)))
{
	if (!*head || !*(head))
	{
		global_info.err_state = 1;
		global_info.err_info = "pint_error";
		return;
	}
	printf("%d\n", (*head)->n);
}
/**
 * pop - removes top of list
 * @head: head of list
 * @n: line number for error
 */
void pop(stack_t **head, unsigned int n __attribute__((unused)))
{
	stack_t *temp;

	if (!head || !(*head))
	{
		global_info.err_state = 1;
		global_info.err_info = "pop_error";
		return;
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
/**
 * swap - swaps the top two elements of a stack
 * @head: head of list
 * @n: line number for error
 */
void swap(stack_t **head, unsigned int n __attribute__((unused)))
{
	stack_t *temp_A;
	stack_t *temp_B;

	if (!head || !(*head) || !(*head)->next)
	{
		global_info.err_state = 1;
		global_info.err_info = "swap_error";
		return;
	}
	temp_B = *head;
	temp_A = (*head)->next;
	temp_B->next = temp_A->next;
	temp_A->next = temp_B;
	temp_A->prev = temp_B->prev;
	temp_B->prev = temp_A;
	if (temp_B->next)
		temp_B->next->prev = temp_B;
	(*head) = temp_A;
}
