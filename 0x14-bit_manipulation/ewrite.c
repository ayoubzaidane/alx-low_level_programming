#include "shell.h"
/**
 * err_write - write to standard error
 * @c: charcter
 * Return: success
 */
int err_write(char c)
{
	static int num;
	static char size[BUFF_WRITE];

	if (c == FLUSH_SIZE || num >= BUFF_WRITE)
	{
		write(2, size, num);
		num = 0;
	}
	if (c != FLUSH_SIZE)
		size[num++] = c;
	return (1);
}
	
/**
 * err_write - write string to standard error
 * @s: string
 * Return: void
 */
void err_writes(char *s)
{
	int num = 0;
	if (s == NULL)
		return;
	while (s[num] != '\0')
	{
		err_write(s[num]);
		num++;
	}
}

/**
 * err_atoi - make string an integer
 * @str: string
 * Return: success
 */
int err_atoi(char *str)
{
	int num;
	unsigned long int digit;

	if (*str == '+')
		str++;

	digit = 0;

	for (num  = 0; str[num] != '\0'; num++)
	{
		if (str[num] >= '0' && str[num] <= '9')
		{
			digit *= 10;
			digit += (str[num] - '0');
			if (digit > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (digit);
}
/**
 * error_ - function to print error
 * @node: argument
 * @error_mesge: error  message type
 * Return: error message
 */
void error_(node_t *node, char *error_mesge)
{
	err_writes(node->ProgName);
	err_writes(": ");
	f_printf(node->err_num, STDERR_FILENO);
	err_writes(": ");
	err_writes(node->argv[0]);
	err_writes(": ");
	err_writes(error_mesge);
}
/**
 * fprintf - function to print integer
 * @ag: user input
 * @file_dis: file discription
 * Return: character printed
 */
int f_printf(int ag, int file_dis)
{
	int num, (*__putchar)(char) = _write, index = 0;
	unsigned int _abs_, tmp;

	if (file_dis == STDERR_FILENO)
		__putchar = err_write;
	if (ag < 0)
	{
		_abs_ = -ag;
		__putchar('-');
		index++;
	}
	else
		_abs_ = ag;
	tmp = _abs_;
	for (num = 1000000000; num > 1; num /= 10)
	{
		if (_abs_ / num)
		{
			__putchar('0' + tmp / num);
			index++;
		}
		tmp %= num;
	}
	__putchar('0' + tmp);
	index++;
	return (index);
}
