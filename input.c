#include"shell.h"
/**
 * handler - handles the ctrl + c
 * @sig: SIGINT
 *
 */
void handler(int sig)
{
	(void)sig;
	_puts("\n");
	_puts("$ ");
}
/**
 * get_input - get pointer inputs
 *
 * Return: pointer to a string
 */
char *get_input(void)
{
	size_t num = 0;
	ssize_t nread;
	char *line = NULL;

	/* getting stdin i/p */
	nread = getline(&line, &num, stdin);
	/* checking EOF condition*/
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	/* chaning the new line value to null*/
	line[nread - 1] = '\0';
	return (line);
}

