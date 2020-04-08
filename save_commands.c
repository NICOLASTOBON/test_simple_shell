#include "holberton.h"
/**
 *
 *
 *
 *
 */
char **save_commands(char *buffer)
{
    int capacity, use, i, index = 0;
    char *temp;
    char **com = malloc(sizeof(char *));
    if (com == NULL)
        return (NULL);
    /* change \n given by getline */
    buffer[strlen(buffer) -1] = '\0';
    if (*buffer == '\0')
        return (NULL);
    i = 0;
    use = 0;
    capacity = 1;
    while (1)
    {
        temp = own_strtok(buffer, " ", &index);
        if (*temp == '\0')
            break;
        com[i] = malloc(strlen(temp) + 1);
        if (com[i] == NULL)
        {
            free_commands(com);
            return(NULL);
        }
        com[i] = temp;
        use++;
        if (use == capacity)
        {
            com = realloc(com, sizeof(temp));
            capacity++;
        }
        i++;
    }
    free(temp);
    temp = NULL;
    com[i] = temp;
    //free(temp);
    return (com);
}