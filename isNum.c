#include "monty.h"
/**
 * isNum - function that takes string and checks
 * if string is number
 * @num: string number
 * Return: 1 is all the characters are digits, 0 if not
 */
int isNum(char *num)
{
	unsigned int i = 0;

	if (num[0] == '-')
	{
		for (i = 1; num[i] || num[i] == ' '; i++)
		{
			if (!(num[i] >= '0' && num[i] <= '9'))
			{
				return (0);
			}
		}
		return (1);
	}
	for (i = 0; num[i] || num[i] == ' '; i++)
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
		{
			return (0);
		}
	}
	return (1);
}
