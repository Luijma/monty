#include "monty.h"
/**
 * pop_error - handles error with pop usage
 * @n: line of error
 */
void pop_error(unsigned int n)
{
	fprintf(stderr, "L<%d>: can't pop an empty stack\n", n);
}
