
#include "ft_printf.h"
#include <stdio.h>
#include "libft.h"
int ft_putchar1(char c)
{
	write(1, &c, 1);
	return 1;
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	int count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			t_flags flags = get_flags(++str);
		}
		else
			count += ft_putchar1(*str++);
	}
	va_end(ap);
	return 0;
}

int main()
{

	ft_printf("feqwfwe%d fewfwe", 123);
	return 0;
}