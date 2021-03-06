#include "monty.h"
/**
 * print_error_usage - print the error message for usage
 * @line_number: line number
 */
void print_error_usage(unsigned int line_number)
{
	dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
