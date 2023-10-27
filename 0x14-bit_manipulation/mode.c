#include "shell.h"
/**
 * interactive - function to check shell interactive mode
 * @node: pointer
 * Return: success
 */
int interactive(node_t *node)
{
	return (isatty(STDIN_FILENO) && node->fd_read <= 2);
}
