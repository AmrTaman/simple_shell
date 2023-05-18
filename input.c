#include"shell.h"
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
	int count = 0, v = 0;

	length = getline(&data, &num, stdin);
	if (length == -1)
	{
		free(data);
		return (NULL);
	}
	data[length - 1] = '\0';
	count = count_string(data);
	arr = malloc(sizeof(char *) * (count));
	if (arr == NULL)
	{
		printf("can't allocate malloc");
		return (NULL);
	}
	count = 0;
	token = strtok(data, "\t ");
	while (token)
	{
		arr[count] = malloc((strlen(token) + 1) * sizeof(char));
		if (arr[count] == NULL)
		{
			printf("can't allocate malloc");
			return (NULL);
		}
		while (token[v])
		{
			arr[count][v] = token[v];
				v++;
		}
		v = 0;
		count++;
		token = strtok(NULL, "\t ");
	}
	free(data);
	return (arr);
}
