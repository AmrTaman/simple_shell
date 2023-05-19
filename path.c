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
	char **paths, **error;
	int i;
	char *env_var, *value, *ret, *full;
	char slash[10] = "/";
	char *n;

printf("sss");
fflush(stdout);
	if (access(name[0], X_OK) == 0)
	{
		return (name);
	}
	printf("sss");
	fflush(stdout);
	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		if (strncmp(env_var, "PATH", 4)
				== 0 && env_var[4] == '=')
		{
			value = env_var + 5;
		}
	}
	printf("sss");
	fflush(stdout);
	strcat(slash, name[0]);
	be = strtok(value, ":");
	while (be)
	{
		strcat(be, slash);
		printf("%s", be);
		if (access(be, X_OK) == 0)
		{
			ret = realloc(name[0], strlen(be) + 1);
			i = 0;
			while (be[i])
			{
				name[0][i] = be[i];
				i++;
			}
			return (name);
		}
		be = strtok(NULL, ":");
	}
	return (name);
}
