#include "ft_printf.h"

int count_digits(int nb)
{
	int res;

	if (nb == 0)
		return (1);
	res = 0;
	while (nb > 0)
	{
		nb /= 10;
		res++;
	}
	return res;
}