#include "shell.h"

/**
  * tokenize - a function that tokenizes a a character array into different
  * strings.
  * @buf: pointer to character array
  * Return: array of strings
  */
char **tokenize(char *buf)
{
	int i;
	char *str;
	char **token = malloc(sizeof(char *) * 1024);

	str = strtok(buf, " \n");
	for (i = 0; str != NULL; i++)
	{
		token[i] = str;
		str = strtok(NULL, " \n");
	}
	return (token);
}
