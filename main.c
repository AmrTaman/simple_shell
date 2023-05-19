#include "shell.h"
/**
 * main - simpel shell
 * @ac: number of arguments
 * @av: array of inputs
 * @env: environment variables array
 *
 * Return: 0
 */

int main(int *ac, char **av, char **env)
{
	char **get;
	char *argv;
	unsigned int i = 0, h = 0;

	while (1)
	{
		printf("#cisfun$ ");
		get = input();
		if (get == NULL)
			break;
		if (get[0] == NULL)
			continue;
		if (access(get[0], X_OK) == -1)
		{
			printf("%s: 1: %s: not found\n", av[0], get[0]);
			continue;
		}
		if (fork() == 0)
		{
			if (execve(get[0], get, env) == -1)
			{
				printf("Error executing command\n");
				exit(EXIT_FAILURE);
			}
		}
		wait(NULL);
		while (get[h])
		{
			h++;
		}
		for (i = 0; i < h; i++)
			free(get[i]);
		free(get);
	}
	return (0);
}
