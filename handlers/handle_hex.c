/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:55:00 by kroyce            #+#    #+#             */
/*   Updated: 2020/12/01 22:12:15 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_hex_digits(unsigned int nb)
{
	int res;

	res = 0;
	while (nb > 0)
	{
		nb /= 16;
		res++;
	}
	return (res);
}

static char		*convert_to_hex(unsigned int nb, t_flags flags)
{
	char	*res;
	int		bytes;
	char	*small_radix;
	char	*big_radix;

	if (nb == 0 && flags.precision != 0)
		return (ft_strdup("0"));
	big_radix = "0123456789ABCDEF";
	small_radix = "0123456789abcdef";
	bytes = count_hex_digits(nb);
	if (!(res = (char*)malloc(sizeof(char) * bytes + 1)))
		return (NULL);
	res[bytes--] = '\0';
	while (bytes >= 0)
	{
		if (flags.type == 'x')
			res[bytes] = small_radix[nb % 16];
		else if (flags.type == 'X')
			res[bytes] = big_radix[nb % 16];
		nb /= 16;
		bytes--;
	}
	return (res);
}

static char		*join_zeroes(char *str, t_flags flags)
{
	char	*res;
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	res = str;
	if (flags.zero == 1)
	{
		while (flags.width-- > len)
		{
			tmp = res;
			if (!(res = ft_strjoin("0", res)))
				return (NULL);
			free(tmp);
		}
	}
	while (flags.precision-- > len)
	{
		tmp = res;
		if (!(res = ft_strjoin("0", res)))
			return (NULL);
		free(tmp);
	}
	return (res);
}

static char		*join_blanks(char *str, t_flags flags)
{
	char	*res;
	char	*tmp;
	int		len;

	res = str;
	len = ft_strlen(str);
	while (flags.width-- > len)
	{
		tmp = res;
		if (flags.minus == 1)
		{
			if (!(res = ft_strjoin(res, " ")))
				return (NULL);
		}
		if (flags.minus == 0)
		{
			if (!(res = ft_strjoin(" ", res)))
				return (NULL);
		}
		free(tmp);
	}
	return (res);
}

int				handle_hex(va_list list, t_flags flags)
{
	char	*res;
	int		arg;
	int		count;

	arg = va_arg(list, int);
	if (!(res = convert_to_hex(arg, flags)))
		return (-1);
	if (!(flags.precision < (int)ft_strlen(res) && flags.precision != -1))
	{
		if (!(res = join_zeroes(res, flags)))
			return (-1);
	}
	if (!(res = join_blanks(res, flags)))
		return (-1);
	count = pf_putstr(res);
	free(res);
	return (count);
}
