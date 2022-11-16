#include "main.h"

/**
 * _strdup - copy with alloc mem
 * @str: string to copy
 * Return: string copied
 */

char *_strdup(char *str)
{
	int i, len;
	char *cpy;

	for (len = 0; str[len]; len++)
		;
	cpy = (char *)malloc(sizeof(char) * len + 1);
	if (cpy == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		cpy[i] = str[i];
	}
	return (cpy);
}
