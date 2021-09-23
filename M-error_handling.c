#include "monty.h"
/*
 * err_usage - prints the proper usage when used wrong
 */
void err_usage()
{
	printf("Usage: monty file\n");
	exit(EXIT_FAILURE);
}
/*
 * err_file - prints error message when file couldn't be opened
 */
void err_file()
{
	printf("Couldn't open file\n");
	exit(EXIT_FAILURE);
}
/*
 * err_memory - prints error when memory error occurs
 */
void err_memory()
{
	printf("Memory error\n");
	exit(EXIT_FAILURE);
}
