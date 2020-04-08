#include "holberton.h"
/**
 *
 *
 *
 *
 */
void enter_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
int prompt(char *argv[], char *env[], char *var[])
{
	char *buffer = NULL;
	char **commands;
	size_t size = 0;
	int num_command = 0, res = 0, status;
	ssize_t ret_getl;
	pid_t pid;
	(void)argv;

	while ((ret_getl = getline(&buffer, &size, stdin)))
	{
		signal(SIGINT, enter_handler);

		if (ret_getl == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			exit(0);
		}
		/**Signal for ctrl + c*/
		num_command++;
		/**function tha splits buffer in words*/
		/**and saves each word in an array of strings*/
		commands = save_commands(buffer);
		pid = fork();
		/** validate if process creation works*/
		if (pid == -1)
			perror("Fork");
			/** error*/
		/** validate if it's child*/
		if (pid == 0)
		{
			res = val_execute_command(commands,buffer, var, env);
			if (res == -1)
			{
				/** path directory */
				printf("%s: %d: command not found: %s\n", argv[0],num_command, commands[0]);
				free(buffer);
				free_commands(commands);
				exit(EXIT_SUCCESS);
			}
		}
		/** its parent*/

		else
		{
			wait(&status);
			if (commands == NULL)
			{
        		free(buffer);
				free_commands(commands);
			}
			/* free buffer, commands and execute exit father */
			else if (strcmp(commands[0], var[0]) == 0)
        		exit_free(buffer, commands);
			else
			{
				free(buffer);
				free_commands(commands);
			}
		}
			buffer = NULL; 
			size = 0;
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, USER, 2);
	}
	return (-1);
}