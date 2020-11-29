#include "ft_printf.h"

int handle_flags(va_list list, t_flags flags)
{
	if (flags.type == 'd' || flags.type == 'i')
		return (handle_int(list, flags));
	else if (flags.type == 's')
		return (handle_str(list, flags));
	else if (flags.type == 'c')
		return (handle_char(list, flags));
	return 0;
}