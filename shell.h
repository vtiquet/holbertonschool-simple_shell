#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/**
* struct command_s - a struct that parse command and its arguments.
* @cmd: the command.
* @args: the arguments.
*/
typedef struct command_s
{
	char *cmd;
	char **args;
} command_t;

command_t *parse_command(char *line);
void free_command(command_t *cmd);
int handle_builtin(command_t *cmd);
void print_help(void);
char *_getenv(const char *name);
char *find_command_in_path(char *command);

char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif /* SHELL_H */
