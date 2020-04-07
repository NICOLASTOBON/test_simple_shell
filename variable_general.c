#include "holberton.h"

void free_commands(char **commands)
{
	int i;
	if (commands == NULL)
		return;
	for (i = 0; commands[i]; i++)
		free(commands[i]);
	free(commands);
}
void exit_free(char *buffer, char **commands)
{
    free(buffer);
    free_commands(commands);
    exit(EXIT_SUCCESS);
}