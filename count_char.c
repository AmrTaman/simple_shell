#include"shell.h"
/**
 * count_char - counts occurence of specifi char
 * @str: srtring
 * @target: target char
 *
 * Return: integer
 */
int count_char(char *str, char target)
{
	int count = 0;

	while (*str != '\0')
	{
		if (*str == target)
		{
			count++;
		}
		str++;
	}
	return (count);
}
