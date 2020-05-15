#include "monty.h"
/**
 * exe_monty - a fucntion that executes the bytecode .m file
 * @av_line: contents from .m file in array of strings
 */
void exe_monty(char **av_line)
{
	char *l_tok = NULL, *cmd = NULL, *num = NULL;
	unsigned int i = 0;

	while (av_line[i])
	{
		global.line_number = i + 1;
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
			free(num);
			if (!(global.value))
				do_non_int_error(l_tok);
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
			else if (strcmp(cmd, "push") == 0)
				print_error_usage(global.line_number);

		}
		get_opcode(cmd)(&global.stack, global.line_number);
		free(l_tok);
		i++;
	}
	free_stack(global.stack);
}
/**
 * do_non_int_error - a function that prints error message
 * @l_tok: string token buffer
 */
void do_non_int_error(char *l_tok)
{
	free(l_tok);
	free_stack(global.stack);
	free(global.av_line);
	free(global.line);
	print_error_usage(global.line_number);
}
/**
 * exe_line - function that executes op_fucntions
 * free the string tok buffer and returns next
 * index value
 * @cmd: command name
 * @l_tok: string token buffer
 * @i: value of index for av_line
 * Return: new index value for av_line
 */
unsigned int exe_line(char *cmd, char *l_tok, unsigned int i)
{
	int new;

	get_opcode(cmd)(&global.stack, global.line_number);
	free(l_tok);
	new = i + 1;
	return (new);
}
