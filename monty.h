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

/**
 * struct error_s - struct used for error handling
 * @opcode: the string used to select fpointer
 * @f: function pointer for errors
 */
typedef struct error_s
{
	char *opcode;
	void (*f)(unsigned int line_number);
} error_t;

/**
 * struct status_s - used to track arguments and error info
 * @node_value: the argument passed to commands
 * @err_state: 1 if error, 0 if no error
 * @err_info: char with error type
 * @ef: function pointer to correct error function
 * @command: command that is going to be executed
 */
typedef struct status_s
{
	char *node_value;
	char *command;
	int err_state;
	char *err_info;
	void (*ef)(unsigned int line_number);
} status_t;

status_t global_info;

void (*selectFunction(char *input))(stack_t **stack, unsigned int line_number);
char **tokenizeInput(char *input);

char *strdup(const char *s);
int _isdigit(char *str);
void free_stacks(stack_t *head);

void push(stack_t **head, unsigned int n);
void pall(stack_t **head, unsigned int n);
void pint(stack_t **head, unsigned int n);
void pop(stack_t **head, unsigned int n);

void error_handler(void);
void initial_errors(FILE *file, int argc, char *argv[]);
void push_error(unsigned int line_number);
void unknown_instruction(unsigned int line_number);
void pint_error(unsigned int line_number);
void malloc_error(unsigned int line_number);
void pop_error(unsigned int line_number);

#endif /* MONTY_H */
