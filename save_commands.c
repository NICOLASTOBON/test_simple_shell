#include "holberton.h"
/**
 *
 *
 *
 *
 */
char **save_commands(char *buffer) // ls -l
{
    int i, w, num_words = 0;/*  index = 0 */;
    char *temp, **com;
    /* change \n given by getline */
    buffer[strlen(buffer) -1] = '\0';   // ls -l\0
    /* numbers delimiters */
    for (w = 0; buffer[w] != '\0' ; w++) 
    {
        if (buffer[w + 1] == ' ' || buffer[w + 1] == '\0') // 2
            num_words++;
    }
    if (num_words == 0)
        return (NULL);
    /* */
    com = malloc(sizeof(char *) * (num_words + 1)); // 3
    if (com == NULL)
        return (NULL);
    /* */
    i = 0;
    temp = strtok(buffer, " ");
    //temp = own_strtok(buffer, " ", &index); // 1.1 = ls\0
    while (*temp != '\0')
    {
        /* if (*temp == '\0')
            break; */
        com[i] = malloc(strlen(temp) + 1); // 3
        if (com[i] == NULL)
        {
            free_commands(com);
            return(NULL);
        }
        strncpy(com[i], temp, strlen(temp) + 1);
        temp = strtok(NULL, " ");
        //com[i] = temp;
        //temp = own_strtok(buffer, " ", &index); 
        i++;
    }
    //free(temp);
    //temp = NULL;
    com[i] = NULL;
    //free(temp);
    return (com);
}