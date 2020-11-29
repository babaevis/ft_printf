#include "ft_printf.h"

int		pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int 	pf_putstr(char *str)
{
	int res;

	res = 0;
	while (*str)
		res += pf_putchar(*str++);
	return res;
}

