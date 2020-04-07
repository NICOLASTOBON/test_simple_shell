#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#define USER "$ "

/** prompt */
int prompt(char *argv[], char *env[], char *var[]);
/** function that saves commands in an array*/
char **save_commands(char *buffer);
/**own strtok function*/
char *own_strtok(char *str, const char *delim);
/**validation and execute commands**/
int val_execute_command(char **commands, char *buffer, char **var, char **env);
/** free double pointer */
void free_commands(char **commands);
/* exit prompt */ 
void exit_free(char *buffer, char **commands);

#endif
