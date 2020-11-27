#include "ft_printf.h"

int handle_int(va_list list, t_flags flags)
{
	int count;

	count = 0;
	int res = va_arg(list, int);

	count += pf_putnbr(res);
	return (count);
}

int handle_flags(va_list list, t_flags flags)
{
	if (flags.type == 'd' || flags.type == 'i')
		return (handle_int(list, flags));
	return 0;
}