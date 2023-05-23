#include"shell.h"
/**
 * _strlen - returns length of a string
 * @s: the string
 *
 * Return: integer
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs comparison of two strangs.
 * @m1: first string
 * @m2: second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *m1, char *m2)
{
	while (*m1 && *m2)
	{
		if (*m1 != *m2)
			return (*m1 - *m2);
		m1++;
		m2++;
	}
	if (*m1 == *m2)
		return (0);
	else
		return (*m1 < *m2 ? -1 : 1);
}


/**
 * _strcpy - copies a string
 * @frst: the destination
 * @scnd: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *frst, char *scnd)
{
	int i = 0;

	if (frst == scnd || scnd == 0)
		return (frst);
	while (scnd[i])
	{
		frst[i] = scnd[i];
		i++;
	}
	frst[i] = 0;
	return (frst);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		fflush(stdout);
		x = 0;
	}
	if (x != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}
