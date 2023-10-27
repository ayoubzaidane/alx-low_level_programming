#include "shell.h"
/**
* get_input - function to gets shell line newline
 * @node argument
 *
 * Return: length of buffer
 */
ssize_t get_input(node_t *node)
{
	ssize_t len = 0;
	static char *size; 
	static size_t i, num, m;
	
	char **size_p = &(node->arg), *ptr;

	_write(FLUSH_SIZE);
	len = input_buf(node, &size, &m);
	if (len == -1) 
		return (-1);
	if (m)
	{
		num = i;
		ptr = size + i; 
		check_chain(node, size, &num, i, m);
		while (num < len)		{
			if (chain_link(node, size, &num))
				break;
			num++;
		}

		i = num + 1; 
		if (i >= m)
		{
			i = m = 0;
			node->buff_cmdline_type = NORM;
		}

		*size_p = ptr;
		return (str_len(ptr));
	}

	*size_p = size;
	return (m);
}


