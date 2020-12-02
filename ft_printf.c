/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:09:25 by kroyce            #+#    #+#             */
/*   Updated: 2020/12/02 16:50:42 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*include <printf.h>
void ft_print_flags(t_flags flags)
{
	printf("\n1) Zero = %d\n", flags.zero);
	printf("2) Minus = %d\n", flags.minus);
	printf("3) Width = %d\n", flags.width);
	printf("4) Precision = %d\n", flags.precision);
	printf("5) Type = %c\n", flags.type);

}*/

static int	handle_flags(va_list list, t_flags flags)
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
	else if (flags.type == '%')
		return (handle_percent(flags));
	return (-1);
}

static int	percent_is_valid(const char *str, int *count)
{
	str++;
	if (*str == '%')
	{
		*count += pf_putchar(*str);
		return (0);
	}
	if (check_zero_flag(str))
		str++;
	if (check_minus_flag(str))
		while (check_minus_flag(str))
			str++;
	if (*str == '*')
		str++;
	else if (ft_isdigit(*str))
		while (ft_isdigit(*str))
			str++;
	if (*str == '.')
		str++;
	if (*str == '*')
		str++;
	else if (ft_isdigit(*str))
		while (ft_isdigit(*str))
			str++;
	return (is_type(*str));
}

static int	find_index(const char *str)
{
	int i;

	i = 0;
	while (!is_type(*str) && *str)
	{
		str++;
		i++;
	}
	if (is_type(*str))
		i++;
	return (i);
}

static int	parse_str(const char *str, va_list list)
{
	int		count;
	int		return_value;
	t_flags	flags;

	while (*str)
	{
		if (*str == '%')
		{
			if (!(percent_is_valid(str, &count)))
			{
				if (*++str == '%')
					str++;
				continue;
			}
			flags = get_flags((char *)++str, list);
			return_value = handle_flags(list, flags);
			if (return_value == -1)
				return (-1);
			count += return_value;
			str += find_index(str);
		}
		else
			count += pf_putchar(*str++);
	}
	return (count);
}

int			ft_printf(const char *str, ...)
{
	int		count;
	va_list	list;

	va_start(list, str);
	count = parse_str(str, list);
	va_end(list);
	return (count);
}
