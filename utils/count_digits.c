#include "ft_printf.h"

int count_digits(int n)
{
	int k;

	if (n < 0)
		n *= -1;
	k = 0;
	while (n > 0)
	{
		n /= 10;
		k++;
	}
	return (k);
}
