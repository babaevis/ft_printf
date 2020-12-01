/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:45:37 by kroyce            #+#    #+#             */
/*   Updated: 2020/12/01 22:47:20 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_hex_digits(long nb)
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

static char		*convert_to_hex(long nb)
{
	char	*res;
	int		bytes;
	char	*radix;

	if (nb == 0)
		return (ft_strdup("0"));
	bytes = count_hex_digits(nb);
	radix = "0123456789abcdef";
	if (!(res = (char*)malloc(sizeof(char) * bytes + 1)))
		return (NULL);
	res[bytes--] = '\0';
	while (bytes >= 0)
	{
		res[bytes] = radix[nb % 16];
		nb /= 16;
		bytes--;
	}
	return (res);
}

static char		*add_prefix(char *str)
{
	char *res;

	if (!(res = ft_strjoin("0x", str)))
		return (NULL);
	free(str);
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

int				handle_pointer(va_list list, t_flags flags)
{
	char	*res;
	void	*ptr;
	int		count;

	ptr = va_arg(list, void *);
	res = convert_to_hex((long)ptr);
	res = add_prefix(res);
	res = join_blanks(res, flags);
	count = pf_putstr(res);
	free(res);
	return (count);
}
