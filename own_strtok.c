#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 */
char *own_strtok(char *str, const char *delim, int *index)
{
	/*static int index = 0;*/
	char *word = malloc(sizeof(char));
	int i = *index, j = 0, k = 0;
	int capacity = 1, use = 0;
	if (str[i] == '\0')
	{
		word[k] = '\0';
		return(word);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (str[i] != delim[j])
			{
				word[k] = str[i];
				use += 1;
			}
			else
			{	
				word[k] = '\0';
				*index = i + 1;
				break;
			}
			j++;
		}
		if (word[k] == '\0')
			break;
		if (use == capacity)
		{
			word = realloc(word, sizeof(char));
			capacity += 1;
		}
		i++;
		k++;
	}
	if (str[i] == '\0')
	{
		word[k] = '\0';
		return (word);
	}
	*index = 1 + 1;
	return (word);
}
