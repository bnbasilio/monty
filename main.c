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
		dprintf(2, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	line = read_textfile(argv[1], 1024);
	av_line = tokenize(line);
	free(line);

	exe_monty(av_line);
	free_av(av_line);
	return (0);
}
