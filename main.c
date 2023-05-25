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
	
	while(input[h])
	{
		if (isspace(input[h]))
			check++;
		h++;
	}
	h--;
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
	int i, h, count = 1;

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
		command = parse_input(input, av[0], count);
		count++;
		if (command == NULL)
			continue;
		if (fork() == 0)
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
