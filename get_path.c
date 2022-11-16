#include "main.h"

/**
 * get_path - get the absolute path of a command
 * @args: command
 * Return: command with absolute path
 */

char **get_path(char **args)
{
	char *path = _strdup(_getenv("PATH"));
	char **split_path = NULL;
	char *bin = NULL;
	int i;

	if (access(args[0], F_OK) == 0)
	{
		free(path);
		path = NULL;
		return (args);
	}
	split_path = split(path, ":");
	free(path);
	path = NULL;

	for (i = 0; split_path[i]; i++)
	{
		bin = malloc((_strlen(split_path[i]) + 1 +
		_strlen(args[0]) + 1) * sizeof(char));
		if (bin == NULL)
			break;

		strcat(bin, split_path[i]);
		strcat(bin, "/");
		strcat(bin, args[0]);

		if (access(bin, F_OK) == 0)
		{
			args[0] = bin;
			break;
		}
		free(bin);
		bin = NULL;
	}
	free(split_path);

	split_path = NULL;

	return (args);
}
