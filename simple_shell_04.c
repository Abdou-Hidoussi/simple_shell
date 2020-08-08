#include "external.h"
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

	token = strtok(str, "\n");
	token = strtok(token, " ");
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		tab[s] = _strdup(token);
		s++;
	}
}
/**
*ifexit - exit
*@str: string
*/
void ifexit(char *str)
{
	str = strtok(str, "\n");
	if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i'
		&& str[3] == 't' && str[4] == '\0')
	{
		exit(0);
	}
}
/**
*main - an interractble shell
*@argc: number of arguments
*@argv: lit of arguments
*Return: 0 works well // -1 if error
*/
int main(int argc, char const *argv[])
{
	(void)argc;
	char *pname, **argum;
	size_t size = 32;
	int i;

	pname = malloc(sizeof(argv[0]));
	pname = _strdup(argv[0]);

	argum = malloc(sizeof(char *));
	if (!isatty(fileno(stdin)))
	{
		write(1, ":) ", 3);
		getline(&argum[0], &size, stdin);
		ifexit(argum[0]);
		stoarr(argum[0], argum);
		if (execvp(argum[0], argum) == -1)
			perror(pname);
		return (0);
	}
	while (1)
	{
		write(1, ":) ", 3);
		getline(&argum[0], &size, stdin);
		ifexit(argum[0]);
		stoarr(argum[0], argum);
		if (fork() == 0)
		{
			if (execvp(argum[0], argum) == -1)
			{
				perror(pname);
			}
			exit(0);
		}
		wait(&i);
	}
	return (0);
}
