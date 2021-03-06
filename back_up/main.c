#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>

/**
 * main - monty program that interprets .m bytecode file
 * @argc: number of arguments
 * @argv: array of argument strings
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **av_line = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	line = read_textfile(argv[1], 1024);
	av_line = tokenize(line);

	exe_monty(av_line);
	free(av_line);
	free(line);
	return (0);
}
