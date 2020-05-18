#include "monty.h"

/**
 * itr_free - function that iterates the index value and
 * and free the token string buffer
 * @l_tok: string token buffer
 * @i: index value
 * Return: incremented index
 */
unsigned int itr_free(char *l_tok, unsigned int i)
{
	unsigned int new = 0;

	new = i + 1;
	free(l_tok);
	return (new);
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
	new = i + 1;
	free(l_tok);
	return (new);
}
/**
 * get_cmd_arg - fucntion that returns the 2nd argument from
 * command
 * @av_line: command line from file
 * Return: second argument in string
 */
char *get_cmd_arg(char *av_line)
{
	char *arg = NULL;

	global.l_tok = strdup(av_line);
	arg = strtok(global.l_tok, " \0");
	return (arg);
}

/**
 * exe_monty - a fucntion that executes the bytecode .m file
 * @av_line: contents from .m file in array of strings
 */
void exe_monty(char **av_line)
{
	char *cmd = NULL, *num = NULL;
	unsigned int i = 0;
	while (av_line[i])
	{
		global.line_number = i + 1;
		cmd = get_cmd_arg(av_line[i]);/*get the command*/
		cmd = strtok(NULL, " ");/*get the 2nd argument*/
		if (cmd != NULL)/*check for 2nd argument*/
		{
			num = strdup(cmd);
			free(global.l_tok);
			cmd = get_cmd_arg(av_line[i]);
			if (cmd[0] == '#')
			{
				i = itr_free(global.l_tok, i);
				free(num);
				continue;
			}
			_args_decision(num, cmd);
		}
		else /*case for only one argument*/
		{
			free(global.l_tok);
			cmd = get_cmd_arg(av_line[i]);
			if (cmd == NULL || cmd[0] == '#')
			{
				i = itr_free(global.l_tok, i);
				continue;
			}
			else if (strcmp(cmd, "push") == 0)
				do_non_int_error(global.l_tok);
		}
		i = exe_line(cmd, global.l_tok, i);
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
	free_av(global.av_line);
	print_error_usage(global.line_number);
}
