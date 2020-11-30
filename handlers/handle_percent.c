#include "ft_printf.h"

static char *join_zeroes(char * str, t_flags flags)
{
	char *tmp;
	char *res;

	res = str;
	while (flags.width-- > 1)
	{
		tmp = res;
		res = ft_strjoin("0", tmp);
		free(tmp);
	}
	return (res);
}

static char *join_blanks(char *str, t_flags flags)
{
	char *res;
	char *tmp;

	res = str;
	while(--flags.width > 0)
	{
		tmp = res;
		if (flags.minus == 1)
		{
			if (!(res = ft_strjoin(res, " ")))
				return (NULL);
		}
		else if (flags.minus == 0)
		{
			if (!(res = ft_strjoin(" ", res)))
				return (NULL);
		}
		free(tmp);
	}
	return (res);
}

int	handle_percent(t_flags flags)
{
	char *res;
	int count;

	if (!(res = ft_strdup("%")))
		return (-1);
	if (flags.zero == 1 && flags.minus == 0 && flags.width > 0)
		res = join_zeroes(res, flags);
	else if (flags.zero == 0 && flags.width != 0)
		res = join_blanks(res, flags);
	count = pf_putstr(res);
	return (count);
}