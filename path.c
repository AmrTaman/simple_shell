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
	int i, x = 0;
	char *env_var, *value, *ret, *full, *path;

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
			path = env_var + 5;
			i = 0;
			while (path[i])
			{
				i++;
			}
			value = malloc(sizeof(char) * i + 1);
			i = 0;
			while(path[i])
			{
				value[i] = path[i];
				i++;
			}
			break;
		}
	}
	ret = malloc(sizeof(char) * strlen(name[0]) + 1);
	strcat(ret, "/");
	strcat(ret, name[0]);
	for(i = 0; name[0][i]; i++)
		name[0][i] = 0;
	be = strtok(value, ":");
	while (be)
	{
		x = strlen(be) + strlen(ret);
		full = realloc(name[0], x + 1);
		strcat(full, be);
		strcat(full, ret);
		i = 0;
		if (access(full, X_OK) == 0)
		{
			return (name);
		}

		be = strtok(NULL, ":");
		for(i = 0; i < x; i++)
			name[0][i] = 0;
	}
	return (name);
}
