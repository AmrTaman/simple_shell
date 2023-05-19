#include"shell.h"
/**
 * get - gets stdin input
 *
 * Return: pointer(data)
 */
char *get(void)
{
	char *data;
	size_t num = 0;
	ssize_t length;

	length = getline(&data, &num, stdin);
	if (length == -1)
	{
		free(data);
		return (NULL);
	}
	if (data[0] == '\n')
		return (data);
	data[length - 1] = '\0';
	return (data);
}

/**
 * input - responsible for getting input from user.
 *
 * Return: pointer
 */
char **input(void)
{
	char *token, *data;
	char **arr;
	int count = 0, v = 0;

	data = get();
	if (data == NULL)
		return (NULL);
	if (data[0] == '\n')
	{
		arr = malloc(sizeof(char *));
		arr[0] = malloc(sizeof(char));
		arr[0] = "r";
		return arr;
	}

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
	arr = path(arr);
	free(data);
	return (arr);
}
