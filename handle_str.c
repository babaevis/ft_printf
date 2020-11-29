#include "ft_printf.h"

static char *join_blanks(char *str, t_flags flags)
{
	char *res;
	char *tmp;
	int len;

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

static char *handle_precision(char *str, int len)
{
	char *res;

	if (len == 0)
	{
		if (!(res = ft_strdup(" ")))
			return (NULL);
		free(str);
		return (res);
	}
	if (len < ft_strlen(str) && len > 0)
	{
		if (!(res = ft_substr(str, 0, len)))
			return(NULL);
		free(str);
		return (res);
	}
	return (str);
}

int handle_str(va_list list, t_flags flags){
	char *res;
	int count;

	res = ft_strdup(va_arg(list, char *));
	res = handle_precision(res, flags.precision);
	res = join_blanks(res, flags);
	count = pf_putstr(res);
	free(res);
	return (count);
}