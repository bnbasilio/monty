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
	char **av_line = NULL;
	char *l_tok = NULL;
	char *cmd = NULL;
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
	exe_monty(av_line);
	return (0);
}
