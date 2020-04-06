#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#define USER "$ "

/** prompt */
int prompt(char *argv[], char *env[], char *var[]);
/** function that saves commands in an array*/
char **save_commands(char *buffer);
/**own strtok function*/
char *own_strtok(char *str, const char *delim);
#endif