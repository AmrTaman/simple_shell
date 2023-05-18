#include<shell.h>
/**
 * input - responsible for getting input from user.
 *
 * Return: pointer
 */
char *input(void)
{
	char *data;
	size_t num = 0;
	ssize_t length;

	length = getline(&data, &num, stdin);
	if (length == -1)
		return (NULL);
	data[length - 1] = '\0';
	return (data);
}
