#include "shell.h"

int main (void)
{
	char **amr;
	int i = 0;

	amr = input();
	while (amr[i])
	{
	printf("%s\n",amr[i]);
	i++;
	}
	return (0);
}
