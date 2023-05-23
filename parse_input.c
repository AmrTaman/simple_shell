#include"shell.h"
/**
 * print_error - prints file not found error
 * @token: input from stdin
 * @count: count of lines
 * @fi: filename
 *
 */
void print_error(char *fi, char *token, int i)
{
	_puts(fi);
	_puts(": ");
	_puts(i);
	_puts(": ");
	_puts(token);
	_puts(": not found\n");
}
/**
 * parse_input - parses input to an array
 * @input: input from stdin
 * @fi: file name
 * @line_count: line counting
 *
 * Return: array of command structure
 */
char **parse_input(char *input, char *fi, int line_count)
{
	int count = 0, m = 0;
	char *token, *trick;
	char **grid;

	count = count_words(input);
	while (input[m])
		m++;
	trick = malloc(sizeof(char) * m + 1);
	m = 0;
	_strcpy(trick, input);
	token = strtok(trick, "\t ");
	if (access(token, X_OK) == -1)
		token = path_check(token);
	if (access(token, X_OK) == -1)
	{
		printf("%s: %d: %s: not found\n",
				fi, line_count, token);
		free(input);
		free(token);
		return (NULL);
	}
	grid = malloc(sizeof(char *) * count);
	count = 0;
	while (token)
	{
		grid[count] = malloc(sizeof(char) * strlen(token) + 1);
		_strcpy(grid[count], token);
		count++;
		if (m == 0)
		{
			free(trick);
			token = strtok(input, "\t ");
		}
		token = strtok(NULL, "\t ");
		m++;
	}
	return (grid);
}
