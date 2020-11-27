#include "ft_printf.h"

t_flags parse_format(char *str, va_list list)
{
	int i;
	t_flags flags;

	i = 0;
	if ((flags.zero = check_zero_flag(str)))
		str++;
	flags.minus = check_minus_flag(str);
	while (check_minus_flag(str))
		str++;
	flags.width = check_width_flag(str, list);
	while(ft_isdigit(*str) || *str == '*')
		str++;
	flags.precision = check_precision_flag(str, list);
	while(*str && !is_type(*str))
		str++;
	if (is_type(*str))
		flags.type = *str;
	if (flags.minus == 1 && flags.zero == 1)
		flags.zero = 0;
	return flags;
}

t_flags get_flags(char *str, va_list list)
{
	t_flags flags;

	flags = parse_format(str, list);
	return flags;
}