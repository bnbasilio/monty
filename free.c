#include "monty.h"
/**
 * free_stack - frees a stack
 * @head: pointer to the head node of a doubly linked list
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
/**
 * free_av - Clear the cmds array of strings
 * @line_av: command strings
 * Return: Nothing
 */
void free_av(char **line_av)
{
	unsigned int i = 0;

	if (line_av == NULL)
		return;
	for (i = 0; line_av[i]; i++)
	{
		free(line_av[i]);
	}

	free(line_av);
}
