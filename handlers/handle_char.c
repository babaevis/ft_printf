#include "ft_printf.h"

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

char *allocate_char(unsigned char c)
{
	char *res;

//	if (c == '\0')
//		return (ft_strdup("\0"));
	if (!(res = (char *)malloc(2)))
		return (NULL);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

int handle_char(va_list list, t_flags flags)
{
	char *res;
	int count;
	unsigned char c;

	c = va_arg(list, int);
	if (!(res = allocate_char(c)))
		return (-1);
	res = join_blanks(res, flags);
	count = pf_putstr(res);
	free(res);
	return (count);
}