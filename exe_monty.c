#include "monty.h"
/**
 * exe_monty - a fucntion that executes the bytecode .m file
 * @av_line: contents from .m file in array of strings
 */
void exe_monty(char **av_line)
{
	char *l_tok = NULL;
	char *cmd = NULL;
	char *num = NULL;
	unsigned int i = 0;
	stack_t *head = NULL;

	while (av_line[i])
	{
		l_tok = strdup(av_line[i]);
		cmd = strtok(l_tok, " \0");
		cmd = strtok(NULL, " ");
		if (cmd != NULL)/*check for another argument after cmd*/
		{
			num = cmd;
			free(l_tok);
			l_tok = strdup(av_line[i]);
			cmd = strtok(l_tok, " ");
			if (!(atoi(num)))
			{
				dprintf(STDERR_FILENO, "L%d: usage: push integer\n", i + 1);
				exit(EXIT_FAILURE);
			}
			value = atoi(num);
		}
		else
		{
			free(l_tok);
			l_tok = strdup(av_line[i]);
			cmd = strtok(l_tok, " ");
		}
		get_opcode(cmd)(&head, 0);
		free(l_tok);
		i++;
	}
	free_stack(head);
}
