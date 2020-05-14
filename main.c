#include "monty.h"

/**
 *main - starting point
 *Return: 0 if successful, 1 otherwise
 */

int main(void)
{
	char *line;
	char **line_av;
	int i;

	line = read_textfile("00.m", 1024);
	line_av = tokenize(line);
	for (i = 0; line_av[i] != NULL; i++)
		printf("%s\n", line_av[i]);
	return (0);
}
