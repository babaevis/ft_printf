#include "ft_printf.h"

int is_type(char c)
{
	return (c == 'd' || c == 'x' || c == 'X' || c == 'u'
	|| c == 'p' || c == 'i' || c == 's');
}

int check_zero_flag(const char *str)
{
	if (str[0] == '0')
		return 1;
	return 0;
}

int check_minus_flag(const char *str)
{
	if(*str == '-')
		return 1;
	return 0;
}

int check_width_flag(char *str, va_list list)
{
	if (*str == '*')
		return va_arg(list, int);
	return (ft_atoi(str));
}

int check_precision_flag(char *str, va_list list)
{
	if (*str == '.')
	{
		if (*(str + 1) == '*')
			return va_arg(list, int);
		return (ft_atoi(str+1));
	}
	return (0);
}

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