/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:45:10 by kroyce            #+#    #+#             */
/*   Updated: 2020/11/02 21:18:18 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FT_LLONG_MAX 9223372036854775807
#define FT_ULLONG_MAX 18446744073709551615ULL

static int	ft_isblank(char c)
{
	if (c == '\n' || c == 32 || c == '\t' || c == '\r'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;
	int					len;

	len = 0;
	res = 0;
	sign = 1;
	while (ft_isblank(*str))
		str++;
	if (*str == '-' && ft_isdigit(*(str + 1)))
	{
		sign = -sign;
		str++;
	}
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
		if (res > FT_LLONG_MAX || (res < FT_ULLONG_MAX && ++len >= 20))
			return (sign == 1 ? -1 : 0);
	}
	return (int)(res * sign);
}
