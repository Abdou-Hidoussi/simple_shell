#include "external.h"
int _getline(char **str, size_t size,char *stdin)
{
	printf("%s", stdin);
}

int main ()
{
	char * str;
	size_t asba;

	str = malloc(sizeof(char) * asba);
	getline(&str, &asba, stdin);
	printf("%s",str);
}