#include "ft_printf.h"

int 	pf_putstr(char *str)
{
	int res;

	res = 0;
	while (*str)
		res += pf_putchar(*str++);
	return res;
}