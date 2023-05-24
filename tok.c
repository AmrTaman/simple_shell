#include "shell.h"
/**
 * _strtok - implememtation of strtok()
 * @str: string
 * @delim: delim
 *
 * Return: string
 */

char *_strtok(char *str, const char *delim)
{
	static char *last_str = NULL;
	static char *last_token = NULL;
	char *token;

	if (str != NULL)
		last_str = str;
	else if (last_str == NULL)
		return (NULL);
	token = last_str;
	while (*last_str != '\0')
	{
		const char *d = delim;

		while (*d != '\0')
		{
			if (*last_str == *d)
			{
				*last_str = '\0';
				last_token = last_str + 1;
				if (token != last_str)
				{
					return (token);
				}
				else
				{
					token = last_token;
					break;
				}
			}
			d++;
		}
		if (last_token != NULL)
		{
			last_str = last_token;
			last_token = NULL;
		}
		else
			last_str++;
	}
	return (token);
}
