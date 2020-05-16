#include "monty.h"

/**
 * get_num_words - returns the nuumber of lines in the file
 * @filename: the file to be scanned
 * Return: number of lines in the file
 */

unsigned int get_num_words(char *filename)
{
	FILE *file;
	char *line = NULL;
	unsigned int line_number = 0;
	ssize_t read;
	size_t n = 0;

	file = fopen(filename, "r");
	if (!file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		free_av(global.av_line);
		free_stack(global.stack);
		free(global.l_tok);
		exit(EXIT_FAILURE);
	}

	do {
		read = getline(&line, &n, file);
		line_number++;
	} while (read != EOF);
	free(line);
	line = NULL;
	fclose(file);
	return (line_number);
}

/**
 * tokenize - splits the file into tokens
 * @filename: file to be scanned
 * Return: array of tokens
 */

char **tokenize(char *filename)
{
	FILE *file;
	char *line = NULL;
	size_t n = 0;
	ssize_t read;
	char **av;
	unsigned int line_number = 0;

	line_number = get_num_words(filename);

	file = fopen(filename, "r");

	av = malloc(sizeof(char *) * (line_number));
	if (!av)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line_number = 0;
	while ((read = getline(&line, &n, file)) != EOF)
	{
		if (line[0] == '\n')
			av[line_number] = strdup(" ");
		else
		{
			line[read - 1] = '\0';
			av[line_number] = strdup(line);
		}
		line_number++;
	}
	av[line_number] = NULL;
	fclose(file);
	free(line);
	return (av);
}
