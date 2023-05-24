#include"shell.h"
/**
 * parsing - returns the tokens
 * @ayy: pointer
 * @token: token pointer
 * @count: integer
 * @input: getline input
 * @x: integer indicates free
 *
 * Return: grid
 */
char **parsing(char *ayy, char *input, int count, char *token, int x)
{
	char **grid;
	int m = 0;

	grid = malloc(sizeof(char *) * count);
	count = 0;
	if (x > 0)
		free(token);
	while (token)
	{
		if (count == 0)
		{
			grid[count] = malloc(sizeof(char) * _strlen(ayy) + 1);
			grid[_strlen(ayy) + 1] = '\0';
			_strcpy(grid[count], ayy);
		}
		if (count != 0)
		{
			grid[count] = malloc(sizeof(char) * _strlen(token) + 1);
			grid[_strlen(token) + 1] = '\0';
			_strcpy(grid[count], token);
		}
		count++;
		if (m == 0)
		{
			token = strtok(input, "\t ");
		}
		token = strtok(NULL, "\t ");
		m++;
	}
	return (grid);
}


/**
 * print_error - prints file not found error
 * @token: input from stdin
 * @i: count of lines
 * @fi: filename
 *
 */
void print_error(char *fi, char *token, int i)
{
	_puts(fi);
	_puts(": ");
	print_number_in(i);
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
	int count = 0, m = 0, i = 0, x = 0;
	char *token, *trick, *check = "env", *ayy;
	char **grid;

	count = count_words(input);
	while (input[m])
		m++;
	trick = malloc(sizeof(char) * m + 2);
	trick[m + 2] = '\0' ;
	m = 0;
	_strcpy(trick, input);
	trick[_strlen(input)] = ' ';
	token = strtok(trick, "\t ");
	while (token[i] == check[i])
		i++;
	if (i == 4)
	{
		env();
		free(trick);
		free(input);
		return (NULL);
	}
	if (access(token, X_OK) == -1)
	{
		token = path_check(token);
		x++;
	}
	ayy = calloc(1, _strlen(token) + 1);
	 _strcpy(ayy, token);
	if (access(ayy, X_OK) == -1)
	{
		free(token);
		print_error(fi, ayy, line_count);
		free(ayy);
		free(input);
		return (NULL);
	}
	grid = parsing(ayy, input, count, token, x);
	free(trick);
	free(ayy);
	return (grid);
}

