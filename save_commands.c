#include "holberton.h"
/**
 *
 *
 *
 *
 */
char **save_commands(char *buffer)
{
    int capacity, use, i;
    char *temp;
    char **com = malloc(sizeof(char *));
    if (com == NULL)
        return (NULL);
    
    i = 0;
    use = 0;
    capacity = 1;
    while (1)
    {
        temp = own_strtok(*buffer, " ");
        if (*temp == '\0')
            break;
        com[i] = temp;
        use++;
        if (use == capacity)
        {
            com = realloc(com, 1);
            capacity++;
        }
        i++;
    }
    return (com);
}