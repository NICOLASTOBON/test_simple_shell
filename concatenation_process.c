#include "holberton.h"
/**
 * 
 * 
 */
char *_copy_string(char *dir_path, char *token, char *commands, int len_dir, int len_comm)
{
    int i, j;

    for (i = 0; i < len_dir && token[i] != '\0'; i++)
        dir_path[i] = token[i];
    dir_path[i] = '/';
    i++;
    for (j = 0; j < len_comm && commands[j] != '\0';i++, j++)
        dir_path[i] = commands[j];
    dir_path[i] = '\0';

    return (dir_path);
}

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0';j++)
		dest[i + j] = src[j];

	return (dest);
}
/**
 * 
 * 
 * 
 */
void concat_commands(char **commands, char *buffer)
{
    char **path_dir = NULL;
    int i = 0;

    path_dir = get_path_dir(commands);
    while (path_dir[i] != NULL)
    {
        if (access(path_dir[i], F_OK) == 0)
            execve(path_dir[i], commands, NULL);
        i++;
    }
    free(buffer);
    free_commands(path_dir);
    free_commands(commands);
    exit(EXIT_SUCCESS);
}
/**
 * 
 * 
 * 
 * 
 */
char **get_path_dir(char **commands)
{
    char *path = NULL, **dir_path = NULL, *token = NULL;
    int num_dir = 0, w, i, len_comm = 0, len_dir = 0;

    path = getenv("PATH");
    for (w = 0; path[w] != '\0'; w++)
	{
	    if (path[w + 1] == ':' || path[w + 1] == '\0')
			num_dir++;
	}
    dir_path = malloc(sizeof(char *) + (num_dir + 1));
    if (dir_path == NULL)
        return (NULL);
    i = 0;
	token = strtok(path, ":");
	while (token != NULL)
	{
        len_dir = _strlen(token);
        len_comm = _strlen(commands[0]);
		dir_path[i] = malloc(sizeof(char) * ( len_dir + len_comm + 2));
		if (dir_path[i] == NULL)
		{
			free_commands(dir_path);
			return (NULL);
		}
        _copy_string(dir_path[i], token, commands[0], len_dir, len_comm);
		token = strtok(NULL, ":");
		i++;
	}
    dir_path[i] = NULL;
    return (dir_path);
}
