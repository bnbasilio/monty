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
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	global.av_line = tokenize(argv[1]);

	exe_monty(global.av_line);
	free_av(global.av_line);

	return (0);
}
