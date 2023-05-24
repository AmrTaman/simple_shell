#include "shell.h"

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
