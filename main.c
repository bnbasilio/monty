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
	global.line = read_textfile(argv[1], 1024);
	global.av_line = tokenize(global.line);
	
	exe_monty(global.av_line);
	free(global.av_line);
	free(global.line);
	return (0);
}
