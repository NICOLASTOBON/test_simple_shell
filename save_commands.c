#include "holberton.h"
/**
 *
 *
 *
 *
 */
char **save_commands(char *buffer)
{
    int i, w, num_words = 0, index = 0;
    char *temp, **com;
    /* change \n given by getline */
    buffer[strlen(buffer) -1] = '\0';   //
    if (*buffer == '\0')
        return (NULL);
    /* numbers delimiters */
    for (w = 0; buffer[w] != '\0' ; w++)
    {
        if (buffer[w + 1] == ' ' || buffer[w + 1] == '\0')
            num_words++;
    }
    /* */
    com = malloc(sizeof(char *) * (num_words + 1));
    if (com == NULL)
        return (NULL);
    /* */
    i = 0;
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
        i++;
    }
    free(temp);
    temp = NULL;
    com[i] = temp;
    //free(temp);
    return (com);
}