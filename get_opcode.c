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
		{"mod", mod_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
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
	fprintf(stderr, "L%d: unknown instruction %s\n", global.line_number, s);
	exit(EXIT_FAILURE);
}
