#include "shell.h"
/**
 * shell_cd - changes the current wordking directory of shell
 * @node: arguments
 * Return: if success 0
 */
int shell_cd(node_t *node)
{
	int _chdir;
	char buff[1024];
	char *num, *cwd;

	num = getcwd(buff, 1024);
	if (!num)
		_writes("TODO: >>getcwd failure<<\n");
	if (!node->argv[1])
	{
		cwd = get_env(node, "HOME=");
		if (cwd != NULL)
			_chdir = chdir((cwd = get_env(node, "PWD=")) ? cwd : "/");
		else
			_chdir = chdir(cwd);
	}
	else if (strcmp(node->argv[1], "-") == 0)
	{
		if (!get_env(node, "OLDPWD="))
		{
			_writes(num);
			_write('\n');
			return (1);
		}
		_writes(get_env(node, "OLDPWD=")), _write('\n');
		_chdir = chdir((cwd = get_env(node, "OLDPWD=")) ? cwd : "/");
	}
	return (0);
}
/**
 * handle_sign - sign in handler
 * @sign_in
 * Return: the dollar sign, exit with ctrl-c
 */
void handle_sign(__attribute__((unused))int sign_in)
{
	_writes("\n");
	_writes("$ ");
	_write(FLUSH_SIZE);
}
