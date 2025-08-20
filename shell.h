#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
#define PROMPT ":) "

extern char **environ;

/**
 * struct builtin_s - Builtin command structure
 * @name: Name of the builtin command
 * @func: Pointer to the builtin function
 *
 * Description: Links a builtin name to its handler function.
 */
typedef struct builtin_s
{
	char *name;
	int (*func)(char **);
} builtin_t;

char *shell_read_line(void);
char **shell_split_line(char *line);
int shell_execute(char **args, char *shell_name, int cmd_count);
char *find_in_path(char *cmd);
char *get_path(char *command);

int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);
int shell_env(char **args);
int shell_execute_builtin(char **args);

#endif /* SHELL_H_ */
