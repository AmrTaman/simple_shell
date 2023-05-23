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
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
