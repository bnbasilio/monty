#include "monty.h"

/**
 * read_textfile - reads a text file and returns a buffer of the bytes read
 * @file: file to be read
 * @chars: number of characters that should be read
 *
 * Return: number of characters actually read
 */

char *read_textfile(const char* file, size_t chars)
{
	int fd;
	char *buffer;
	ssize_t read_len;

	if (!file)
		return (NULL);

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);

	buffer = malloc(sizeof(char) * chars);
	if (!buffer)
	{
		close(fd);
		return (NULL);
	}

	read_len = read(fd, buffer, chars);
	if (read_len == -1)
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[read_len] = '\0';

	close(fd);
	return (buffer);
}

/**
 * tokenize - splits a buffer into tokens
 * @fb: file buffer to be tokenized
 */

char **tokenize(char *fb)
{
	char **av;

	if (!fb)
		return (NULL);

	av[0] = strtok(fb, '\n');
	for (i = 1; fb != NULL; i++)
		av[i] = strtok(NULL, '\n');
	av[i] = NULL;

	return (av);
}
