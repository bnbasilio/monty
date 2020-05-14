#include "monty.h"
int value;
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
	new->n = value;

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

void pall_dstack_list(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void)line_number;
	head = *stack;
	for( ;head; head = head->next)
	{
		printf("%d\n", head->n);
	}
}
