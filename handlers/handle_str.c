/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:47:56 by kroyce            #+#    #+#             */
/*   Updated: 2020/12/01 22:49:27 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char		*handle_precision(char *str, int len)
{
	char *res;

	if (len == 0)
	{
		if (!(res = ft_strdup("\0")))
			return (NULL);
		free(str);
		return (res);
	}
	if (len < (int)ft_strlen(str) && len > 0)
	{
		if (!(res = ft_substr(str, 0, len)))
			return (NULL);
		free(str);
		return (res);
	}
	return (str);
}

int				handle_str(va_list list, t_flags flags)
{
	char	*res;
	int		count;
	char	*arg;

	arg = va_arg(list, char *);
	if (!arg)
	{
		if (!(res = ft_strdup("(null)")))
			return (-1);
	}
	else
	{
		if (!(res = ft_strdup(arg)))
			return (-1);
	}
	if (!(res = handle_precision(res, flags.precision)))
		return (-1);
	if (!(res = join_blanks(res, flags)))
		return (-1);
	count = pf_putstr(res);
	free(res);
	return (count);
}
