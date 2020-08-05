#include "external.h"
/**
 * _strdup - duplicate a string
 * @str: the string to duplicate
 *
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
*main - an interractble shell
*@argc: number of arguments
*@argv: lit of arguments
*Return: 0 works well // -1 if error
*/
int main(int argc, char const *argv[])
{
	(void)argc;
	char *cmd_in, *pname, **argum;
	size_t size = 32;
	int i;

	pname = malloc(sizeof(argv[0]));
	pname = _strdup(argv[0]);
	cmd_in = (char *)malloc(size * sizeof(char));
	if (cmd_in == NULL)
	{
		perror("Unable to allocate cammand buffer");
		exit(-1);
	}
	argum = malloc(sizeof(cmd_in));
	argum[1] = NULL;
	if (!isatty(fileno(stdin)))
	{
		write(1, "#cisfun$ ", 9);
		getline(&cmd_in, &size, stdin);
		cmd_in = strtok(cmd_in, "\n");
		argum[0] = cmd_in;
		if (execv(cmd_in, argum) == -1)
			perror(pname);
		return (0);
	}
	while (1)
	{
		write(1, "#cisfun$ ", 9);
		getline(&cmd_in, &size, stdin);
		cmd_in = strtok(cmd_in, "\n");
		argum[0] = cmd_in;
		if (fork() == 0 && execv(cmd_in, argum) == -1)
				perror(pname);
		wait(&i);
	}
	free(cmd_in);
	free(pname);
	free(argum);
	return (0);
}
