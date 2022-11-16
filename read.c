#include "main.h"

/**
 * readline - read the input of the user
 * Return: the input
 */

char *readline(void)
{
	char *input = NULL;
	ssize_t get;
	size_t bufsize = 0;

	get = getline(&input, &bufsize, stdin);
	if (get == -1)
	{
		free(input);
		exit(0);
	}

	return (input);
}
