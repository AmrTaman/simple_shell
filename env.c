#include "shell.h"
/**
 * env - prints env variable
 *
 *Return: 0
 */

int env(void)
{
	int i = 0;

	while (environ[i])
	{
		puts(environ[i]);
		i++;
	}
	return (0);
}

