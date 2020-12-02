/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:50:51 by kroyce            #+#    #+#             */
/*   Updated: 2020/12/02 17:13:03 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*join_zeroes(char *num, int count, t_flags flags)
{
	char *tmp;
	char *res;

	res = num;
	if (!ft_strncmp(num, "0", 1))
	{
		if (flags.precision == 0)
		{
			free(res);
			return (ft_strdup("\0"));
		}
		count--;
	}
	while (count-- > 0)
	{
		tmp = res;
		if (!(res = ft_strjoin("0", tmp)))
			return (NULL);
		free(tmp);
	}
	return (res);
}

static char		*treat_zeroes(unsigned int arg, t_flags flags)
{
	char	*res;
	int		count;
	int		digits;

	digits = count_unsigned_digits(arg);
	count = 0;
	if (!(res = ft_unsigned_itoa(arg)))
		return (NULL);
	if ((flags.zero == 0 && flags.precision == -1))
		return (res);
	if (flags.zero == 1 && flags.width > digits)
	{
		while (flags.width-- > digits)
			count++;
	}
	while (flags.precision > digits++)
		count++;
	if (!(res = join_zeroes(res, count, flags)))
		return (NULL);
	return (res);
}

static char		*join_blanks(char *str, t_flags flags)
{
	char *res;
	char *tmp;

	if (!(res = ft_strdup(str)))
		return (NULL);
	while (flags.minus == 0 && flags.width-- > (int)ft_strlen(str))
	{
		tmp = res;
		if (!(res = ft_strjoin(" ", res)))
			return (NULL);
		free(tmp);
	}
	while (flags.minus == 1 && flags.width-- > (int)ft_strlen(str))
	{
		tmp = res;
		if (!(res = ft_strjoin(res, " ")))
			return (NULL);
		free(tmp);
	}
	return (res);
}

static char		*treat_blanks(char *arg, t_flags flags)
{
	char *tmp;

	tmp = arg;
	if (flags.width > (int)ft_strlen(arg) && !flags.zero)
	{
		if (!(arg = join_blanks(arg, flags)))
			return (NULL);
		free(tmp);
	}
	return (arg);
}

int				handle_unsigned(va_list list, t_flags flags)
{
	int				count;
	char			*res;
	unsigned int	arg;

	arg = va_arg(list, unsigned int);
	if (!(res = treat_zeroes(arg, flags)))
		return (-1);
	if (!(res = treat_blanks(res, flags)))
		return (-1);
	count = pf_putstr(res);
	free(res);
	return (count);
}
