#include "monty.h"
/**
 * _args_decision - a function that makes decision
 * between two arguments: number string and command opcode
 * @num: number string
 * @cmd: opcode command
 */
void _args_decision(char *num, char *cmd)
{
	if (isNum(num))
	{
		global.value = atoi(num);
		free(num);
	}
	else if (!isNum(num) && (strcmp(cmd, "push") == 0))
	{
		free(num);
		do_non_int_error(cmd);
	}
	else
		free(num);
}
