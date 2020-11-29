#include "ft_printf.h"

int handle_flags(va_list list, t_flags flags)
{
	if (flags.type == 'd' || flags.type == 'i')
		return (handle_int(list, flags));
	else if (flags.type == 's')
		return (handle_str(list, flags));
	else if (flags.type == 'c')
		return (handle_char(list, flags));
	else if (flags.type == 'x' || flags.type == 'X')
		return (handle_hex(list, flags));
	else if (flags.type == 'u')
		return (handle_unsigned(list, flags));
	else if (flags.type == 'p')
		return (handle_pointer(list, flags));
	return -1;
}