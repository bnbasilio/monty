#include "monty.h"
/**
 * exe_monty - a fucntion that executes the bytecode .m file
 * @av_line: contents from .m file in array of strings
 */
void exe_monty(char **av_line)
{
	char *l_tok = NULL, *cmd = NULL, *num = NULL;
	unsigned int i = 0;
	stack_t *head = NULL;

	while (av_line[i])
	{
		global.line_number = i + 1;
		printf("av[%d] is %s\n", i, av_line[i]);
		l_tok = strdup(av_line[i]);
		cmd = strtok(l_tok, " \0");
		cmd = strtok(NULL, " ");
		if (cmd != NULL)/*check for another argument after cmd*/
		{
			num = strdup(cmd);
			free(l_tok);
			l_tok = strdup(av_line[i]);
			cmd = strtok(l_tok, " ");
			global.value = atoi(num);
			printf("value: %d\n", global.value);
			free(num);
			if (!(global.value))
			{
				free_all(l_tok, num);
				print_error_usage(i + 1);
			}
		}
		else
		{
			free(l_tok);
			l_tok = strdup(av_line[i]);
			cmd = strtok(l_tok, " ");
			if (cmd == NULL)
			{
				i++;
				free(l_tok);
				continue;
			}
		}
		get_opcode(cmd)(&head, global.line_number);
		free(l_tok);
		i++;
	}
	free_stack(head);
}
