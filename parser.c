#include "ft_printf.h"

static int is_numeric_type(char c)
{
	if (c == 'd' || c == 'i' ||  c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

static t_flags parse_format(char *str, va_list list)
{
	t_flags flags;

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
	return flags;
}

t_flags get_flags(char *str, va_list list)
{
	t_flags flags;

	flags = parse_format(str, list);
	if (!is_numeric_type(flags.type))
		flags.zero = 0;
	if (is_numeric_type(flags.type) && flags.precision > -1)
		flags.zero = 0;
	if (flags.width < 0)
	{
		flags.width *= -1;
		flags.minus = 1;
		flags.zero = 0;
	}
	return flags;
}