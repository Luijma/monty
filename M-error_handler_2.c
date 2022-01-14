#include "monty.h"
/**
 * pop_error - handles error with pop usage
 * @n: line of error
 */
void pop_error(unsigned int n)
{
	fprintf(stderr, "L<%d>: can't pop an empty stack\n", n);
}
/**
 * swap_error - handles error with swap usage
 * @n: line of error
 */
void swap_error(unsigned int n)
{
	fprintf(stderr, "L<%d>: can't swap, stack too short\n", n);
}
void monty_error(unsigned int n __attribute__((unused)))
{
	fprintf(stderr, "USAGE: monty file\n");
}
