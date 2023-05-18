#include"shell.h"
#include<string.h>
/**
 * input - responsible for getting input from user.
 *
 * Return: pointer
 */
char **input(void)
{
	char *data, *token, *token2;
	char **arr;
	size_t num = 0;
	ssize_t length;
	int count = 0, in_word = 0, i = 0;

	length = getline(&data, &num, stdin);
	if (length == -1)
		return (NULL);
	data[length - 1] = '\0';

	while (data[i] != '\0')
	{
		if (isspace(data[i]))
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	printf("%d\n", count);
	arr = malloc(sizeof(char *) * (count + 1));

	count = 0;
	token = strtok(data, "\t ");
	while (token)
	{
		arr[count] = token;
		count++;
		token = strtok(NULL, "\t ");
	}
	return (arr);
}
