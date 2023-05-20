#include"shell.h"
/**
 * path_check - checking the path file
 * @ip: input string
 *
 * Return: pointer of th path
 */
char *path_check(char *ip)
{
	char *path, *env_var, *value, *token;
	int i, count = 0, m = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		if (strncmp(env_var, "PATH", 4)
				== 0 && env_var[4] == '=')
		{
			i = 0;
			path = env_var + 5;
			count = count_char(path, ':');
			value = malloc(sizeof(char) *
					(strlen(path) +
					(count * (strlen(ip) + 1))) + 1);
			while (path[i])
			{
				count = 0;
				if (path[i + 1] == ':' || path[i + 1] == '\0')
				{
					value[m] = path[i];
					m++;
					value[m] = '/';
					m++;
					while(ip[count])
					{
						value[m] = ip[count];
						m++;
						count++;
					}
					m--;
				}
				else
				{
					value[m] = path[i];
				}
				i++;
				m++;
			}
			value[m] = '\0';
			break;
		}
	}
	token = strtok(value, ":");
	while (token)
	{
		if (access(token, X_OK) == 0)
		{
			free(value);
			return (token);
		}
		token = strtok(NULL, ":");
	}
	free(value);
	return (ip);
}
