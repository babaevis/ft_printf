#include "ft_printf.h"

static char *join_zeroes(char *num, int count, t_flags flags)
{
	char *tmp;
	char *res;

	res = num;
	if (!ft_strncmp(num, "0", 1))
	{
		if (flags.precision == 0)
		{
			free(res);
			return ft_strdup("\0");
		}
		count--;
	}
	while (count-- > 0)
	{
		tmp = res;
		res = ft_strjoin("0", tmp);
		free(tmp);
	}
	return (res);
}

static char *zero_padd(unsigned int arg, t_flags flags)
{
	char *res;
	int count;
	int digits;

	digits = count_unsigned_digits(arg);
	count = 0;
	if(!(res = ft_unsigned_itoa(arg)))
		return NULL;
	if ((flags.zero == 0 && flags.precision == -1))
		return res;
	if (flags.zero == 1 && flags.width > digits)
	{
		while (flags.width-- > digits)
			count++;
	}
	while (flags.precision > digits++)
		count++;
	res = join_zeroes(res, count, flags);

	return (res);
}

static char 	*join_blanks(char *str, t_flags flags)
{
	char *res;
	char *tmp;

	res = ft_strdup(str);
	while (flags.minus == 0 && flags.width-- > (int)ft_strlen(str))
	{
		tmp = res;
		res = ft_strjoin(" ", res);
		free(tmp);
	}
	while(flags.minus == 1 && flags.width-- > (int)ft_strlen(str))
	{
		tmp = res;
		res = ft_strjoin(res, " ");
		free(tmp);
	}
	return (res);
}

static char	*blanks_padd(char *arg, t_flags flags)
{
	char *tmp;

	tmp = arg;
	if (flags.width > (int)ft_strlen(arg) && !flags.zero)
	{
		arg = join_blanks(arg, flags);
		free(tmp);
	}
	return (arg);
}

int handle_unsigned(va_list list, t_flags flags)
{
	int count;
	char *res;

	unsigned int arg = va_arg(list, unsigned int);
	res = zero_padd(arg, flags);
	res = blanks_padd(res, flags);
	count = pf_putstr(res);
	free(res);
	return (count);
}