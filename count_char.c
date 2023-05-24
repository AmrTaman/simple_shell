nclude"shell.h"
/**
 * print_number_in -Print Number Putchar
 * @n:Integer
 * Return: void
 */
void print_number_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number_in(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * count_char - counts occurence of specifi char
 * @str: srtring
 * @target: target char
 *
 * Return: integer
 */
int count_char(char *str, char target)
{
	int count = 0;

	while (*str != '\0')
	{
		if (*str == target)
		{
			count++;
		}
		str++;
	}
	return (count);
}
