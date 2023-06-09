#include"shell.h"
/**
 * count_words - counts strings
 * @data: data from input function
 *
 * Return: integer
 */
int count_words(char *data)
{
	int i = 0, count = 0, in_word = 0;

	while (data[i] != '\0')
	{
		if (_isspace(data[i]))
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
	return (count + 1);
}

/**
 * _isspace - discover spaces and return their length
 * @c: integr
 *
 * Return: 1 or 0
 */
int _isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
			c == '\r' || c == '\f' || c == '\v')
		return (1);
	else
		return (0);
}

