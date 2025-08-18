#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

int main(int argc, char **argv);
int handle_builtin(command_t *cmd);
void print_help(void);

char *_getenv(const char *name);
char *find_command_in_path(char *command);

command_t *parse_command(char *line);
void free_command(command_t *cmd);

#endif /* SHELL_H */
