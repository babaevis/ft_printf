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
