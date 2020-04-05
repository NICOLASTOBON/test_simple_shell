#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 */
char *own_strtok(char *str, const char *delim)
{
	static int index = 0;
	char *word = malloc(sizeof(char)*1);
	int i = index, j = 0, k = 0;
	int capacity = 1, use = 0;

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
				index = i + 1;
				break;
			}
			j++;

		}
		if (word[k] == '\0')
			break;
		if (use == capacity)
		{
			word = (char *)realloc(word, 1);
			capacity += 1;
		}
		i++;
		k++;
	}
	if (str[i] == '\0')
	{	
		word[k] = '\0';
		index = i;
	}
	return (word);
}
int main(void)
{
    char s[100] = "my name is khan";
    char delm[3] = " ";
    //char newstr[100];
    char *str = own_strtok(s, delm);
    while (*str != '\0'){
        printf("%s ", str);
        free(str);
        str = own_strtok(s, delm);
    }
	printf("\n");
    return 0;
}