#include "main.h"
#include "printf.h"

/**
 * num_built - returns the right builtin
 * Return: right buitlin
 */

int num_built(void)
{
	char *builtin_cmd[] = {
	"cd",
	"exit",
	"env"
	};

	return (sizeof(builtin_cmd) / sizeof(char *));
}

/**
 * exit_bn - built-in exit
 * @args: not used
 * Return: 0
 */

int exit_bn(char **args __attribute__((__unused__)))
{
	exit(0);
}

/**
 * cd_bn - change directory
 * @args: directory to go
 * Return: 1 on success, O on failure
 */

int cd_bn(char **args)
{
	if (args[1] ==  NULL)
	{
		chdir(getenv("HOME"));
		return (1);
	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			_printf("%s: %s: No such file or directory\n", args[0], args[1]);
			return (-1);
		}
	}
	return (0);
}

/**
 * env_bn - env builtin
 * @args: unused
 * Return: 1
 */

int env_bn(char **args __attribute__((__unused__)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_printf("%s\n", environ[i]);
	}
	exit(0);
}

/**
 * exec_built - execute the builtins
 * @args: command
 * Return: 1 on success, else function exec
 */

int exec_built(char **args)
{
	char *builtin_cmd[] = {
	"cd",
	"exit",
	"env"
	};
	int (*builtin_function[]) (char **) = {
	&cd_bn,
	&exit_bn,
	&env_bn,
	};
	int i;

	if (args[0] == NULL)
	{
	return (1);
	}

	for (i = 0; i < num_built(); i++)
	{
		if (_strcmp(args[0], builtin_cmd[i]) == 0)
		{
			return ((*builtin_function[i])(args));
		}
	}

	return (0);
}
