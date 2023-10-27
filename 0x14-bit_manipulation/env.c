#include "shell.h"
/**
 * shell_exit - Implement the exit built-in, that exits the shell
 * @node: argument
 * Return: exit
 */
int shell_exit(node_t *node)
{
	int num;

	if (node->argv[1])
	{
		num = err_atoi(node->argv[1]);
		if (num == -1)
		{
			node->status = 2;
			error_(node, "Illegal number: ");
			err_writes(node->argv[1]);
			err_write('\n');
			return (1);
		}
		node->err_exit = err_atoi(node->argv[1]);
		return (-2);
	}
	node->err_exit = -1;
	return (-2);
}
