#include "shell.h"
/**
 * delim - delimeter
 * @m: m
 * @delim: delimeter
 *
 * Return: 0
 */
unsigned int delim(char m, char *delim)
{
	while(*delim != '\0')
	{
		if(m == *delim)
			return (1);
		delim++;
	}
	return (0);
}
/**
 * _strtok - implememtation of strtok()
 * @str: string
 * @delim: delim
 *
 * Return: string
 */
char *_strtok(char *str, const char *delim)
{
	static char *strb;

	if(!str)
		str = strb;
	if(!str)
		return (NULL);
	while(1)
	{
		if(delim(*str, delim))
		{
			str++;
			continue;
		}
		if(*str == '\0')
			return (NULL); 
		break;
	}
	char *ret = str;

	while(1)
	{
		if(*str == '\0')
		{
			strb = str;
			return (ret);
		}
		if(delim(*str, delim))
		{
			*str = '\0';
			strb = str + 1;
			return (ret);
		}
		str++;
	}
}
