#include "holberton.h"

int val_execute_command(char **commands, char *buffer, char **var, char **env)
{
    (void)env;
    if (commands == NULL)
    {
        free(buffer);
        exit(EXIT_SUCCESS);
    }
    /* compare and execute exit*/
    else if (strcmp(commands[0], var[0]) == 0)
        exit_free(buffer, commands);
    /* compare and execute env */
    //else if (strcmp(commands[0], var[1]))
       // show_env(commands, buffer, env);
    /* compare and execute clear */
    //else if (strcmp(commands[0], var[2]))
        //_clear(buffer, commands);
    /* validation command in each file and execute */
    else if (access(commands[0], F_OK) == 0)
        execve(commands[0],commands, NULL);
    return (-1);
}