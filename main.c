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
	char *input;
	char **command;
	int i, h;

	signal(SIGINT, handler);
	while (1)
	{
		printf("$ ");
		input = get_input();
		if (input == NULL)
		{
			break;
		}
		else if (input[0] == '\0')
		{
			free(input);
			continue;
		}
		command = parse_input(input, av[0]);
		if (command == NULL)
			continue;
		if(fork() == 0)
			execve(command[0], command, NULL);

		wait(NULL);
		h = 0;
		while (command[h])
			h++;
		for (i = 0; i <= h; i++)
			free(command[i]);
		free(command);
		free(input);
	}
	return (0);
}
