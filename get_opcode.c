#include "monty.h"
/**
 * get_opcode - function that selects the operation
 * @s: string to compare for opcode
 * Return: Nothing
 */
void (*get_opcode(char *s))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", add_dstack_list},
		{"pall", pall_dstack_list},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L: unknown instruction %s\n", s);
	exit(EXIT_FAILURE);
}
/**
 * execute_line - function that executes string
 * @s: opcode name
 * @stack: starting node at the stack doubly linked list
 * @line_number: line number in integer
 */
void execute_line(char *s, stack_t **stack, unsigned int line_number)
{
		instruction_t ops[] = {
		{"push", add_dstack_list},
		{"pall", pall_dstack_list},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, s);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
