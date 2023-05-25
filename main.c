#include "shell.h"
/**
 * checker - simpel shell
 * @input: user input
 *
 * Return: 0 or 1
 */
int checker(char *input)
{
	int h = 0, check = 0;

	while (input[h])
	{
		if (isspace(input[h]))
			check++;
		h++;
	}
	if (h == check)
	{
		free(input);
		return (1);
	}
	return (0);
}
/**
 * main - simpel shell
 * @ac: number of arguments
 * @av: array of inputs
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *input;
	char **command;
	int i, h, count = 1, status, s = 0;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		if (ac)
			input = get_input();
		if (input == NULL)
			exit(EXIT_SUCCESS);
		else if (input[0] == '\0')
		{
			free(input);
			continue;
		}
		if (checker(input))
			continue;
		command = parse_input(input, av[0], count, s);
		count++;
		if (command == NULL)
			continue;
		pid = fork();
		if (pid == 0)
		{
			execve(command[0], command, NULL);
		}
		waitpid(pid, &status, 0);
		s = WEXITSTATUS(status);
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
