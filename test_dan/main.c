#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main()
{
	char *line[]= {"    push    200 ", "   push   -9","push 2",
		       "push 64", "push 69","push -",
		       "pall", NULL};
	char *l_tok = NULL;
	char *cmd= NULL;
	char *num = NULL;
	unsigned int i = 0;
	stack_t *head = NULL;

	while(line[i])
	{
		l_tok = strdup(line[i]);
		cmd = strtok(l_tok," \0");
		cmd = strtok(NULL, " ");
		if (cmd != NULL)
		{
			num = cmd;
			free(l_tok);
			l_tok = strdup(line[i]);
			cmd = strtok(l_tok, " ");
			if (!(value = atoi(num)))
			{
				dprintf(STDERR_FILENO,"L%d: usage: push integer\n", i + 1);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			free(l_tok);
			l_tok = strdup(line[i]);
			cmd = strtok(l_tok, " ");
		}
		get_opcode(cmd)(&head, 0);
		free(l_tok);
		i++;
	}
	return (0);
}
