/* path_list.c */
#include "shell.h"

/**
 * main - Demonstrates PATH directory handling.
 * Return: Always 0.
 */
int main(void)
{
	path_dir_t *path_head;

	printf("--- Exercise: Print PATH directories ---\n");
	print_path_dirs();

	printf("\n--- Exercise: PATH Linked List ---\n");
	path_head = build_path_list();
	if (path_head)
	{
		printf("Linked list created successfully.\n");
		free_list(path_head);
	}
	else
	{
		printf("Failed to create linked list.\n");
	}
	return (0);
}

/**
 * print_path_dirs - Prints each directory in the PATH variable.
 */
void print_path_dirs(void)
{
	char *path_env = getenv("PATH");
	char *path_copy;
	char *dir;

	if (!path_env)
		return;

	path_copy = strdup(path_env);
	if (!path_copy)
		return;

	dir = strtok(path_copy, ":");
	while (dir)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
}

/**
 * build_path_list - Builds a linked list from PATH directories.
 * Return: Head of the linked list.
 */
path_dir_t *build_path_list(void)
{
	char *path_env = getenv("PATH");
	char *path_copy;
	char *token;
	path_dir_t *head = NULL, *current, *new_node;

	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		new_node = malloc(sizeof(path_dir_t));
		if (!new_node)
		{
			free_list(head);
			free(path_copy);
			return (NULL);
		}
		new_node->dir = strdup(token);
		new_node->next = NULL;

		if (!head)
		{
			head = new_node;
			current = new_node;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (head);
}

/**
 * free_list - Frees a linked list.
 * @head: The head of the list.
 */
void free_list(path_dir_t *head)
{
	path_dir_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->dir);
		free(temp);
	}
}
