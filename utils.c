#include "ft_printf.h"

int	count_digits(int n)
{
	int k;

	k = 0;
	while (n > 0)
	{
		n /= 10;
		k++;
	}
	return (k);
}


int	power(int n)
{
	int res;

	res = 1;
	while (--n)
		res *= 10;
	return (res);
}

static void	print_nums(int n)
{
	if (n == 0)
		ft_putchar('0');
	if (n == -2147483648)
		ft_putstr("-2147483648");
}

int		pf_putnbr(int n)
{
	int k;
	int res;
	int ret;

	ret = n;
	if (n == 0 || n == -2147483648)
	{
		print_nums(n);
		return count_digits(n);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	k = power(count_digits(n));
	while (k > 0)
	{
		res = n / k;
		ft_putchar(res + '0');
		n = n - res * k;
		k /= 10;
	}
	return count_digits(ret);
}
