#include"shell.h"
/**
 * _strlen - returns length of a string
 * @s: the string
 *
 * Return: integer
 */
nt _strlen(char *s)
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
 * @x: length of comparison
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *m1, char *m2, int x)
{
	int i = 0;

	while (m1[i] && m2[i] && x >= i)
	{
		if (*m1 != *m2)
			return (*m1 - *m2);
		m1++;
		m2++;
		i++;
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
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
return;
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
	return (write(1, &c, 1));
}
