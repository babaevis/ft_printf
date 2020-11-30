#include "ft_printf.h"

int		pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}