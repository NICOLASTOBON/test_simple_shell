#include "holberton.h"
/**
 * 
 * 
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
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
    char **concat_com, **path_dir, *temp_dir;
    int num_commands = 0, w, i, j;

    for (w = 0; buffer[w] != '\0'; w++)
	{
	    if (buffer[w + 1] == ':' || buffer[w + 1] == '\0')
			num_commands++;
	}
    path_dir = get_path_dir();
    concat_com = malloc(sizeof(char *) * (num_commands + 1));
    if (concat_com == NULL)
        return;
    i = 0;
    while (path_dir[i] != NULL)
    {
        temp_dir = path_dir[i];
        _strcat(temp_dir, "/");
        _strcat(temp_dir, commands[0]);
        if(access(temp_dir, F_OK) == 0)
            break;
        i++;
    }
    j = 1;
    concat_com[0] = temp_dir;
    printf("%s",concat_com[0]);
    printf("%s",commands[0]);
    while(commands[j] != NULL)
    {
        _strncpy(concat_com[j],commands[j], _strlen(commands[j]));
        j++;
    }
    concat_com[j] = NULL;
    if (access(concat_com[0], F_OK) == 0)
    {
        printf("entre aqui");
        execve(concat_com[0], concat_com, NULL); 
    }
}
/**
 * 
 * 
 * 
 * 
 */
char **get_path_dir(void)
{
    char *path, **dir_path, *token;
    int num_dir = 0, w, i;

    path = getenv("PATH");
    for (w = 0; path[w] != '\0'; w++)
	{
	    if (path[w + 1] == ':' || path[w + 1] == '\0')
			num_dir++;
	}
    dir_path = malloc(sizeof(char *) * (num_dir + 1));
    if (dir_path == NULL)
        return (NULL);
    i = 0;
	token = strtok(path, ":");
	while (token != NULL)
	{
		dir_path[i] = malloc(_strlen(token) + 1);
		if (dir_path[i] == NULL)
		{
			free_commands(dir_path);
			return (NULL);
		}
		_strncpy(dir_path[i], token, _strlen(token) + 1);
		token = strtok(NULL, ":");
		i++;
	}
    dir_path[i] = NULL;
    return (dir_path);
}
