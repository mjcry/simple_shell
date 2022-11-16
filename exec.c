#include "main.h"

/**
 * exec - execute the command
 * @args: command to execute
 * Return: 1 on Success
 */

int exec(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork fails");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		return (-1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}
