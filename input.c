#include"shell.h"
#include<string.h>
/**
 * input - responsible for getting input from user.
 *
 * Return: pointer
 */
char **input(void)
{
	char *data, *token;
	char **arr;
	size_t num = 0;
	ssize_t length;
	int count = 0;

	length = getline(&data, &num, stdin);
	if (length == -1)
	{
		free(data);
		puts("\n");
		return (NULL);
	}

	data[length - 1] = '\0';
	count = count_string(data);

	arr = malloc(sizeof(char *) * (count + 1));

	count = 0;
	token = strtok(data, "\t ");
	while (token)
	{
		arr[count] = token;
		count++;
		token = strtok(NULL, "\t ");
	}
	free(data);
	return (arr);
}
