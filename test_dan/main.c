#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **av_line= NULL;
	char *l_tok = NULL;
	char *cmd= NULL;
	char *num = NULL;
	unsigned int i = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		dprintf(2, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	line = read_textfile(argv[1], 1024);
	av_line = tokenize(line);

	while(av_line[i])
	{
		l_tok = strdup(av_line[i]);
		cmd = strtok(l_tok," \0");
		cmd = strtok(NULL, " ");
		if (cmd != NULL)/*check for another argument after cmd*/
		{
			num = cmd;
			free(l_tok);
			l_tok = strdup(av_line[i]);
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
			l_tok = strdup(av_line[i]);
			cmd = strtok(l_tok, " ");
		}
		get_opcode(cmd)(&head, 0);
		free(l_tok);
		i++;
	}
	return (0);
}
