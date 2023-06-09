#include"shell.h"
/**
 * setting_string - sets the path to required destination
 * @path: path string
 * @ip: file
 * @count: length of path string
 *
 * Return: a string pointer
 */
char *setting_string(char *path, char *ip, int count)
{
	int i = 0, m = 0;
	char *value;

	value = malloc(((_strlen(path) +
				(count * (_strlen(ip) + 1))) + 1) * sizeof(char));
	value[((_strlen(path) +
				(count * (_strlen(ip) + 1))))] = '\0';
	while (path[i])
	{
		count = 0;
		if (path[i + 1] == ':' || path[i + 1] == '\0')
		{
			value[m] = path[i];
			m++;
			value[m] = '/';
			m++;
			while (ip[count])
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
	return (value);
}

/**
 * path_check - checking the path file
 * @ip: input string
 *
 * Return: pointer of th path
 */
char *path_check(char *ip)
{
	char *path, *env_var, *value, *token, *last;
	int i = 0, count = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		if (_strcmp(env_var, "PATH", 4)
				== 0 && env_var[4] == '=')
		{
			i = 0;
			path = env_var + 5;
			count = count_char(path, ':');
			value = setting_string(path, ip, count + 1);
			break;
		}
	}
	token = _strtok(value, ":");
	while (token)
	{
		if (access(token, X_OK) == 0)
		{
			last = malloc(sizeof(char) * _strlen(token) + 1);
			last[_strlen(token)] = '\0';
			_strcpy(last, token);
			free(value);
			return (last);
		}
	token = _strtok(NULL, ":");
	}
	free(value);
	return (ip);
}

