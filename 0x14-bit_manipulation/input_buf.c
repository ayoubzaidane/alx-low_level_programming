#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @node: argument
 * @size: double pointer address
 * @m: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(node_t *node, char **size, size_t *m)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*m)
	{

		free(*size);
		*size = NULL;
		signal(SIGINT, handle_sign);
#if USE_GETLINE
		r = getline(size, &len_p, stdin);
#else
		r = get_line(node, size, &len_p);
#endif
		if (r > 0)
		{
			if ((*size)[r - 1] == '\n')
			{
				(*size)[r - 1] = '\0';
				r--;
			}
			node->count_flag_line = 1;
			remove_comments(*size);
			history_list(node, *size, node->histcount++);
			
			{
				*m = r;
				node->buff_cmd_line = size;
			}
		}
	}
	return (r);
}
