#include "shell.h"
/**
 * get_env - function to get enviroment variable
 * @node: argument
 * @index: name of environment variable
 * Return: NULL
 */
char *get_env(node_t *node, const char *index)
{
	char *s;
	list_t *h = node->env;

	while (h)
	{
		s = start_ptr(h->str, index);
		if (s && *s)
			return (s);
		h = h->next;
	}
	return (NULL);
}
