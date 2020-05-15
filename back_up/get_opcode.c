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
