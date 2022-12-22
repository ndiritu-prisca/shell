#include "shell.h"

/**
  * main - entry point of the program
  * @ac: argument count
  * @av: argument vector
  * Return: 0 on success
  */

int main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	while (1)
	{
		char **token;
		char *buf;

		printf("#cisfun$ ");


		buf = line_get();
		token = tokenize(buf);
		check_str(buf, token);

	}
	return (0);
}
