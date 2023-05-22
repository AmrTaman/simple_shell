#include"shell.h"
/**
 * parse_input - parses input to an array
 * @input: input from stdin
 * @fi: file name
 *
 * Return: array of command structure
 */
char **parse_input(char *input, char *fi)
{
	int count = 0, m = 0;
	char *token, *trick;
	char **grid;

	count = count_words(input);
	while (input[m])
		m++;
	trick = calloc(1, sizeof(char) * m + 1);
	m = 0;
	strcpy(trick, input);
	token = strtok(trick, "\t ");
	if (access(token, X_OK) == -1)
		token = path_check(token);
	if (access(token, X_OK) == -1)
	{
		printf("%s: %d: %s: not found\n",
				token, X_OK, fi);
		free(input);
		free(trick);
		return (NULL);
	}
	grid = calloc(1, sizeof(char *) * count);
	count = 0;
	while (token)
	{
		grid[count] = calloc(1, sizeof(char) * strlen(token) + 1);
		strcpy(grid[count], token);
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
