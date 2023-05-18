#include"shell.h"
/**
 * count_string - counts strings
 * @data: data from input function
 *
 * Return: integer
 */
int count_string(char *data)
{
	int i = 0, count = 0, inword;

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
	return (count);
}
