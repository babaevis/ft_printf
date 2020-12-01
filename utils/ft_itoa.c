/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:13:35 by kroyce            #+#    #+#             */
/*   Updated: 2020/11/30 09:50:50 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*return_values(int n)
{
	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	return (ft_strdup("0"));
}

char		*ft_itoa(int n)
{
	char	*res;
	int		k;
	int		sign;

	if (n == 0 || n == -2147483648)
		return (return_values(n));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	k = count_digits(n) + sign;
	if (!(res = (char *)malloc(k + 1)))
		return (NULL);
	res[k] = 0;
	while (--k >= 0 + sign)
	{
		res[k] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}
