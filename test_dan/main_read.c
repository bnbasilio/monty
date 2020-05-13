#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *buffer;

	if (ac != 2)
	{
		dprintf(2, "Usage: %s filename\n", av[0]);
		exit(1);
	}
	buffer = read_textfile(av[1], 1024);
	printf("%s", buffer);
	printf("%ld\n",strlen(buffer));
	free(buffer);
	return (0);
}
