#include "ft_printf.h"
int count_digits(int n)
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

int count_unsigned_digits(unsigned int n)
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

char		*ft_unsigned_itoa(unsigned int n)
{
	char	*res;
	int		k;

	if (n == 0)
		return (ft_strdup("0"));
	k = count_unsigned_digits(n);
	if (!(res = (char *)malloc(k + 1)))
		return (NULL);
	res[k] = 0;
	while (--k >= 0)
	{
		res[k] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}
