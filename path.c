#include "shell.h"
/**
 * path - get the path
 *@name: input
 *
 * Return: full path
 */

char **path(char **name)
{
	char *be;
	char **paths;
	int i;
	char *env_var, *value;
	char *n;

	if (access(name[0], X_OK) == 0)
	{
		return (name);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		if (strncmp(env_var, "PATH", 4)
				== 0 && env_var[4] == '=')
		{
			value = env_var + 5;
		}
	}
	n = strcat("/", name[0]);
	be = strtok(value, ":");
	while (be)
	{
		if (access(strcat(be, n), X_OK) == 0)
		{
			relloc(name[0], strlen(strcat(be, n)) + 1);
		}
		be = strtok(NULL, ":");
	}
}
