#include "monty.h"
global_t global;

/**
 * add_dstack_list - a function that adds new node at
 * the beginning of the stack
 * @stack: address of the starting stack
 * @line_number: not used
 * Return: nothing
 */
void add_dstack_list(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void) line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->next = NULL;
	new->n = global.value;

	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		*stack = new;
	}
}
/**
 * pall_dstack_list - a function that prints the list of stack
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 * Return: Nothing
 */
void pall_dstack_list(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void)line_number;
	if (!stack)
		return;
	head = *stack;
	for ( ; head; head = head->next)
	{
		printf("%d\n", head->n);
	}
}

/**
 * pint_monty - prints the value at the top of the stack
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 */

void pint_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head)
		printf("%d\n", head->n);
	else
	{
		/*FREE*/
		free(global.av_line);
		free_stack(global.stack);
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_monty - removes the top element of the stack
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 */

void pop_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!(*stack))
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(current);
}

/**
 * swap_monty - swaps the top two elements of the stack
 * @stack: a starting address of stack doubly linked list
 * @line_number: line number in file
 */

void swap_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		/*FREE*/
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	temp->prev = NULL;
	temp->next = *stack;
	*stack = temp;
}
