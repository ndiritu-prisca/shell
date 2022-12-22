#include "shell.h"

/**
  * line_get - a function that reads from stdin
  * and writes into a buffer
  * Return: the buffer
  */
char *line_get(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t n;

	n = getline(&buffer, &len, stdin);
	if (n == -1)
	{
		putchar('\n');
		exit(-1);
	}
	return (buffer);
}
