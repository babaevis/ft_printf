#include "ft_printf.h"

static int count_hex_digits(int nb)
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

static char *convert_to_hex(int nb, char flag)
{
	char *res;
	int bytes;
	char *small_radix = "0123456789abcdef";
	char *big_radix = "0123456789ABCDEF";
	bytes = count_hex_digits(nb);
	if(!(res = (char*)malloc(sizeof(char) * bytes + 1)))
		return (NULL);
	res[bytes--] = '\0';
	while (bytes >= 0)
	{
		if (flag == 'x')
			res[bytes] = small_radix[nb % 16];
		else if (flag == 'X')
			res[bytes] = big_radix[nb % 16];
		nb /= 16;
		bytes--;
	}
	return (res);
}

static char *join_zeroes(char *str, t_flags flags)
{
	char *res;
	char *tmp;
	int len;

	len = ft_strlen(str);
	res = str;
	if (flags.precision < len)
		return str;
	while (flags.precision-- > len)
	{
		tmp = res;
		if (!(res = ft_strjoin("0", res)))
			return (NULL);
		free(tmp);
	}
	return (res);
}

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

int handle_hex(va_list list, t_flags flags)
{
	char *res;
	int arg;
	int count;

	arg = va_arg(list, int);
	res = convert_to_hex(arg, flags.type);
	res = join_zeroes(res, flags);
	res = join_blanks(res, flags);
	count = pf_putstr(res);
	free(res);
	return (count);
}