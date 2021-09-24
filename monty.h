#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *node_value;
void (*selectFunction(char *input))(stack_t **stack, unsigned int line_number);
char **tokenizeInput(char *input);


void file_loop(char *line_buf, FILE file, int line_count,
		size_t line_size, char **line_array,
		void (*func_ptr)(stack_t **, unsigned int));

char *strdup(const char *s);
int _isdigit(char *str);
void free_stacks(stack_t *head);

void push(stack_t **head, unsigned int n);
void pall(stack_t **head, unsigned int n);
void pint(stack_t **head, unsigned int n);
void pop(stack_t **head, unsigned int n);

#endif /* MONTY_H */
