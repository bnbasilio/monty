#include "monty.h"

/**
 * read_textfile - reads a text file and returns a buffer of the bytes read
 * @file: file to be read
 * @chars: number of characters that should be read
 *
 * Return: number of characters actually read
 */

char *read_textfile(const char *file, size_t chars)
{
	int fd;
	char *buffer;
	ssize_t read_len;

	if (!file)
		return (NULL);

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * (chars + 1));
	if (!buffer)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
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
 * Return: an array of tokens
 */

char **tokenize(char *fb)
{
	char *fb_dup = NULL;
	char *av_tok, **av = NULL;
	int i, str_count, n;

	if (!fb)
		return (NULL);

	fb_dup = strdup(fb);
	for (n = 0, str_count = 0; fb_dup[n]; n++)
	{
		if (fb_dup[n] == '\n')
			str_count++;
	}
	free(fb_dup);

	av = malloc(sizeof(char *) * (str_count + 1));
	if (!av)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	av_tok = strtok(fb, "\n");
	av[0] = av_tok;
	for (i = 1; av_tok; i++)
	{
		av_tok = strtok(NULL, "\n");
		av[i] = av_tok;
		
	}

	return (av);
}
