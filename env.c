#include "shell.h"
/**
 * env - prints env variable
 *
 * @trick: free
 * @input: free
 *Return: 0
 */

int env(char *trick, char *input)
{
	int i = 0;

	while (environ[i])
	{
		puts(environ[i]);
		i++;
	}
	free(trick);
	free(input);
	return (0);
}

