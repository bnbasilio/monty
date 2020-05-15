#include "monty.h"

/**
 * add_monty - adds the top two elements of the stack
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 */

void add_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * nop - does not do anything
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 */

void nop_monty(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_monty - subtracts the top element from the second top element of the stack
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 */

void sub_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n -= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * mul_monty - multiplies the top two elements of the stack
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 */

void mul_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n *= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * div_monty - divides the second top element by the top element of the stack
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 */

void div_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	if ((*stack)->n == 0)
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->n /= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
