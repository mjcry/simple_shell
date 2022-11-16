#include "main.h"


/**
 * loop - loop the prompt
 */

void loop(void)
{
	char *read;
	char **args;
	int status;

	signal(SIGINT, signalHandler);

	do {
		write(STDIN_FILENO, "$ ", 2);
		read = readline();
		args = split(read, " \t\r\n");
		status = exec_built(args);
		get_path(args);
		exec(args);


		free(read);
		free(args);
		args = NULL;
	} while (status == 0);
	exit(0);
}
