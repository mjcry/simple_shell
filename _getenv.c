#include "main.h"

/**
 * _getenv - get the environnement
 * @name : environnement's name
 * Return: poitner to the environnement
 */

char *_getenv(char *name)
{
	int i = 0;
	unsigned int j;
	int k;

	while (environ[i] != NULL)
	{
		if (_strstr(environ[i], name))
		{
			j = 0;
			k = 0;
			while (name[j])
			{
				if (environ[i][j] == name[j])
					k++;
				j++;
			}
			if (k == _strlen(name))
			return (_strstr(environ[i], name) + _strlen(name));
		}
		i++;
	}
	return (NULL);
}
