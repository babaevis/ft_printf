#include "ft_printf.h"
#include <stdio.h>

//void ft_print_flags(t_flags flags)
//{
//	printf("\n1) Zero = %d\n", flags.zero);
//	printf("2) Minus = %d\n", flags.minus);
//	printf("3) Width = %d\n", flags.width);
//	printf("4) Precision = %d\n", flags.precision);
//	printf("5) Type = %c\n", flags.type);
//
//}

int percent_is_valid(const char *str, int *count)
{
	str++;
	if (*str == '%')
	{
		*count += pf_putchar(*str);
		return (0);
	}
	if (check_zero_flag(str))
		str++;
	else if (check_minus_flag(str))
		while (check_minus_flag(str))
			str++;
	if (*str == '*')
		str++;
	else if(ft_isdigit(*str))
		while (ft_isdigit(*str))
			str++;
	if (*str == '.')
		str++;
	if (*str == '*')
		str++;
	else if(ft_isdigit(*str))
		while (ft_isdigit(*str))
			str++;
	return (is_type(*str));
}

int parse_str(const char *str, va_list list)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (!(percent_is_valid(str, &count)))
			{
				str++;
				continue;
			}
			t_flags flags = get_flags((char *)++str, list);
//			ft_print_flags(flags);
			count += handle_flags(list, flags);
			while (!is_type(*str) && *str)
				str++;
			if(is_type(*str))
				str++;
		}
		else
			count += pf_putchar(*str++);
	}
	return count;
}

int ft_printf(const char *str, ...)
{
	int count;
	va_list list;
	va_start(list, str);

	count = parse_str(str, list);
	va_end(list);
	return count;
}
