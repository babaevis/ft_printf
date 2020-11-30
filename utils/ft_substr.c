/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:31:56 by kroyce            #+#    #+#             */
/*   Updated: 2020/11/02 16:36:09 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup("\0"));
	i = 0;
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	while (i != start)
		i++;
	start = 0;
	while (len-- && *str)
	{
		res[start] = str[i];
		i++;
		start++;
	}
	res[start] = 0;
	return (res);
}
