#include "monty.h"
/**
 * error_handler - handles the errors after getting main info
 */
void error_handler(void)
{
	int idx = 0;
	error_t err_func[] = {
		{"malloc_error", malloc_error},
		{"push_error", push_error},
		{"pint_error", pint_error},
		{"pop_error", pop_error},
		{"swap_error", swap_error},
		{"unknown_instruction", unknown_instruction},
		{"monty_error", monty_error},
		{NULL, NULL}
	};

	while (err_func[idx].opcode)
	{
		if (strcmp(global_info.err_info, err_func[idx].opcode) == 0)
		{
			global_info.ef = err_func[idx].f;
		}
		idx++;
	}
}
/**
 * malloc_error - handles memory allocation error
 * @line_number: line number of error
 */
void malloc_error(unsigned int line_number __attribute__((unused)))
{
	fprintf(stderr, "Error: malloc failed\n");
}
/**
 * push_error - handles error with push usage
 * @line_number: line number of error
 */
void push_error(unsigned int line_number)
{
	fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
}
/**
 * unknown_instruction - handles error with invalid commands
 * @line_number: line number of error
 */
void unknown_instruction(unsigned int line_number)
{
	fprintf(stderr, "L<%u>: unknown instruction <%s>\n",
			line_number, global_info.command);
}
/**
 * pint_error - handles error with pint usage
 * @line_number: line number of error
 */
void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L<%u>: can't pint, stack empty\n", line_number);
}
