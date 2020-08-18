#include "external.h"
/**
*free_all - exit
*@str: array of string to be free
*@pname: string to be free
*/
void free_all(char **str, char *pname)
{
	free(*str);
	free(str);
	free(pname);
}
/**
*ifexit - exit
*@str: string to be free
*@pname: string to be free
*/
void ifexit(char **str, char *pname)
{
	str[0] = strtok(str[0], "\n");
	if (str[0][0] == 'e' && str[0][1] == 'x' && str[0][2] == 'i'
		&& str[0][3] == 't' && str[0][4] == '\0')
	{
		free_all(str, pname);
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
	char *pname, **argum, *hold;
	size_t size = 32;
	int i = 0;

	pname = malloc(sizeof(argv[0]));
	pname = _strdup(argv[0]);
	if (!isatty(fileno(stdin)))
	{
		hold = malloc(sizeof(char *));
		getline(&hold, &size, stdin);
		argum = malloc(sizeof(char *) * fid_div(hold));
		argum[0] = hold;
		ifexit(argum, pname);
		stoarr(argum[0], argum);
		if (execvp(argum[0], argum) == -1)
			perror(pname);
		free_all(argum, pname);
		return (0);
	}
	while (1)
	{
		write(1, "$ ", 2);
		hold = malloc(sizeof(char *));
		getline(&hold, &size, stdin);
		argum = malloc(sizeof(char *) * fid_div(hold));
		argum[0] = hold;
		ifexit(argum, pname);
		stoarr(argum[0], argum);
		if (fork() == 0)
		{
			if (execvp(argum[0], argum) == -1)
			{
				perror(pname);
			}
			free_all(argum, pname);
			exit(0);
		}
		wait(&i);
	}
	return (0);
}
