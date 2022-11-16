#include "main.h"

/**
 * split - split the command in tokens
 * @line: command to split
 * @limit: characters limiters
 * Return: splited command
 */

char **split(char *line, char *limit)
{
	unsigned int bufsize = 64, new_bufsize = 0, idx = 0;
	char **tokens = NULL;
	char *token, **tokens_back;

	tokens = malloc(sizeof(char *) * bufsize);
	if (tokens == NULL)
	{
		perror("Malloc tokens fails");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, limit);
	while (token)
	{
		tokens[idx] = token;
		idx++;

		if (idx >= bufsize)
		{
			new_bufsize = bufsize + 64;
			tokens_back = tokens;
			tokens = _realloc(tokens, bufsize, new_bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				free(tokens_back);
				perror("Realloc tokens fails");
				exit(EXIT_FAILURE);
			}
			bufsize = new_bufsize;
		}
		token = strtok(NULL, limit);
	}
	tokens[idx] = NULL;
	return (tokens);

