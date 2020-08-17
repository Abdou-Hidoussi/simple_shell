#include "external.h"
/**
*fid_div - 0
*@s: char
*Return: j
*/
int fid_div(char *s)
{
	int i = 0, j = 2;

	while (*s != '\0' && s)
	{
		if (*s == ' ')
			j++;
		s++;
		i++;
	}
	return (j);
}
/**
*_strlen - 0
*@s: char
*Return:: i
*/
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (*s != '\0' && s)
	{
		s++;
		i++;
	}
	return (i);
}
/**
 * _strdup - duplicate a string
 * @str: the string to duplicate
 * Return: string.
 */
char *_strdup(char const *str)
{
	char *p;
	int i, j;


	if (str == NULL)
	{
		return (NULL);
	}


	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}


	p = malloc(i + 1 * sizeof(char));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}

	j = 0;
	while (j <= i)
	{
		p[j] = str[j];
		j++;
	}
	return (p);
}
/**
*stoarr - convert a string to array seperated by space
*@str: string
*@tab: the table to fill from 1 index
*/
void stoarr(char *str, char **tab)
{
	char *token;
	int s = 1;

	token = malloc(sizeof(char *));
	token = strtok(str, "\n");
	token = strtok(token, " ");
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		tab[s] = _strdup(token);
		s++;
	}
	free(token);
}
