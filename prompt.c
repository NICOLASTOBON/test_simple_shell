#include "holberton.h"
/**
 *
 *
 *
 *
 */
int prompt(char *argv[], char *env[], char *var[])
{
	char *buffer = NULL;
	char **commands;
	ssize_t size = 0;
	int num_command = 0;
	ssize_t ret_getl;
	pid_t pid;
	int res = 0;

	while (ret_getl == getline(&buffer, &size, stdin))
	{
		/**Signal for ctrl + c*/
		num_command++;
		/**function tha splits buffer in words*/
		/**and saves each word in an array of strings*/
		commands = save_commands(buffer);

		pid = fork();
		/** validate if process creation works*/
		if (pid == -1)
		{

		}
			/** error*/
		/** validate if it's child*/
		if (pid == 0)
			res = val_execute_command(commands,buffer, var, env);
		/** its parent*/
		else
		{
			/* code */
		}
	}
	return (-1);
}