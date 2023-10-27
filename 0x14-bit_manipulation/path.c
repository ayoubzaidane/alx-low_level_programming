#include "shell.h"
/**
 * command_path – function to create a path in our shell
 * @node: arguments
 *
 * Return: nothing
 */
void command_path(node_t *node)
{
	int index;
	char *path = NULL;
	int k;

	node->path = node->argv[0];
	if (node->count_flag_line == 1)
	{
		node->err_num++;
		node->count_flag_line = 0;
	}
	for (index = 0, k = 0; node->arg[index]; index++)
		if (!delim(node->arg[index], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_cmd_path(node, get_env(node, "PATH="), node->argv[0]);
	if (path)
	{
		node->path = path;
		handle_path(node);
	}
	else
	{
		if ((interactive(node) || get_env(node, "PATH=")
			|| node->argv[0][0] == '/') && command_line(node, node->argv[0]))
			handle_path(node);
		else if (*(node->arg) != '\n')
		{
			node->status = 127;
			error_(node, "no such file or directory\n");
		}
	}
}

/**
 * handle_path - function called forks to handle command execution
 * @node: argument
 *
 * Return: void
 */
void handle_path(node_t *node)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(node->path, node->argv, environ_init(node)) == -1)
		{
			free_node(node, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(node->status));
		if (WIFEXITED(node->status))
		{
			node->status = WEXITSTATUS(node->status);
			if (node->status == 126)
				error_(node, "Permission denied\n");
		}
	}
}

