#include "shell.h"

/**
  * check_str -  a function that checks a string
  * @buf: buffer to be read
  * @token: array to be used
  * Return: nothing
  */
void check_str(char *buf, char **token)
{
	char ptr[] = "/bin/";
	char ptr2[100];

	if (buf[0] == '/')
	{
		check_access(token);
		execute(buf, token);
	}
	else if (buf[0] != '/' && (strcmp(token[0], "exit") == 0))
	{
		exit(0);
	}
	else if (buf[0] != '/' && (strcmp(token[0], "env") == 0))
	{
		print_env();
	}

	else
	{
		strcpy(ptr2, ptr);
		strcat(ptr2, token[0]);
		token[0] = ptr2;
		strcpy(ptr2, ptr);
		strcat(ptr2, buf);
		buf = ptr2;
		check_access(token);
		execute(buf, token);
	}
}
/**
  * check_access - a function that checks if a the first token in an
  * array of strings is executable
  * @token: array to be used
  * Return: nothing
  */
void check_access(char **token)
{
	int x;

	x = access(token[0], X_OK);
	if (x == -1)
	{
		perror("./shell");
	}
}
/**
  * execute - a function that executes an executable file
  * @buf: buffer holding character array
  * @token: buffer holding array of strings
  * Return: nothing
  */
void execute(char *buf, char **token)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(buf, token, environ);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
		exit(-1);
	}
}
