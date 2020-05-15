#include "monty.h"

/**
 * mod_monty - computes the remainder of the division of the
 *             second top element by the top element of the stack
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 */

void mod_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	if ((*stack)->n == 0)
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->n %= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * pchar_monty - prints the char at the top of the stack
 * @stack: a starting address of stack doubly linked list
 * @line_no: line number in file
 */

void pchar_monty(stack_t **stack, unsigned int line_no)
{
	if (!(*stack))
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr_monty - prints the string starting at the top of the stack
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 */

void pstr_monty(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack && (*stack)->n > 0 && (*stack)->n <= 127)
	{
		printf("%c", (*stack)->n);
		*stack = (*stack)->next;
	}
	printf("\n");
}
