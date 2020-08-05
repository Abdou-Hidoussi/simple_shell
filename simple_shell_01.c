#include "external.h"
/**
*main - an interractble shell
*@argc: number of arguments
*@argv: lit of arguments
*Return: 0 works well // -1 if error
*/
int main(int argc, char const *argv[])
{
	(void)argc;
	char *cmd_in;
	char *argum[] = { NULL };
	size_t size = 32;

	cmd_in = (char *)malloc(size * sizeof(char));
	if (cmd_in == NULL)
	{
		perror("Unable to allocate cammand buffer");
		exit(-1);
	}
	do {
		write(1, "#cisfun$ ", 9);
		getdelim(&cmd_in, &size, '\n', stdin);
		if (cmd_in[0] == 'e')
			break;
		if (execve(cmd_in, argum, NULL) == -1)
			perror(argv[0]);
	} while (isatty(fileno(stdin)));
	free(cmd_in);
	return (0);
}
