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
	char **av = NULL;
	unsigned int i = 0;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	av = read_tokenize(argv[1]);
	while (av[i])
	{
		printf("Line Number %d: ", i + 1);
		printf("av[%d] is %s\n", i, av[i]);
		i++;
	}
	free_av(av);

	return (0);
}
