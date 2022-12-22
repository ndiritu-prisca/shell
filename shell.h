#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

extern char **environ;

char *line_get();
char **tokenize(char *buf);
void check_str(char *buf, char **token);
void execute(char *buf, char **token);
void check_access(char **token);
char **copy_env(void);
void print_env(void);

#endif /*MAIN_H*/
