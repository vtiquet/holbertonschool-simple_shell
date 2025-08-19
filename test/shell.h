/* shell.h */
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/* Structures for PATH linked list */
/**
 * struct path_dir - Linked list node for a PATH directory.
 * @dir: Directory string.
 * @next: Pointer to the next node.
 */
typedef struct path_dir
{
	char *dir;
	struct path_dir *next;
} path_dir_t;

/* Prototypes for env_functions.c */
void print_env_global(void);
void print_env_addresses(char **env);
char *_getenv(const char *name);

/* Prototypes for path_list.c */
void print_path_dirs(void);
path_dir_t *build_path_list(void);
void free_list(path_dir_t *head);

/* Prototypes for env_modifiers.c */
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif /* SHELL_H */
