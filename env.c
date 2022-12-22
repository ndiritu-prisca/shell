#include "shell.h"

/**
  * copy_env - a function that copies the environment
  *
  * Return: pointer to copied array of strings
  */
char **copy_env(void)
{
	int count, i, j;
	char **copy;

	count = 0;
	while (environ[count] != NULL)
		count++;
	copy = malloc((count + 1) * sizeof(char *));

	if (copy == NULL)
		return (NULL);
	for (i = 0; i < count; i++)
	{
		copy[i] = strdup(environ[i]);

		if (copy[i] == NULL)
		{
			for (j = 0; j < 1; j++)
				free(copy[j]);
			free(copy);
			return (NULL);
		}
	}
	copy[count] = NULL;
	return (copy);
	}
/**
  * print_env - a function that prints the envrionment
  *
  * Return: nothing
  */
void print_env(void)
	{
	int i;
	char **buf = copy_env();

	for (i = 0; buf[i] != NULL; i++)
	{
		printf("%s\n", buf[i]);
	}
}
