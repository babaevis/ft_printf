#include "ft_printf.h"

static char *join_blanks(char *str, t_flags flags)
{
	char *res;
	char *tmp;

	res = str;
	while(--flags.width)
	{
		tmp = res;
		if (flags.minus == 1)
		{
			if (!(res = ft_strjoin(res, " ")))
				return (NULL);
		}
		else if (flags.minus == 0)
			if (!(res = ft_strjoin(" ", res)))
				return (NULL);
		free(tmp);
	}
	return (res);
}

int handle_char(va_list list, t_flags flags)
{
	char *res;
	int count;
	unsigned char c;

	c = va_arg(list, int);
	res = (char *)&c;
	if (!(res = ft_strdup(res)))
		return (-1);
	res = join_blanks(res, flags);
	count = pf_putstr(res);
	free(res);
	return (count);
}