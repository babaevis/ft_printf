
#include "ft_printf.h"
#include <stdio.h>
#include "libft.h"
int ft_putchar1(char c)
{
	write(1, &c, 1);
	return 1;
}

void ft_print_flags(t_flags flags)
{
	printf("\n1) Zero = %d\n", flags.zero);
	printf("2) Minus = %d\n", flags.minus);
	printf("3) Width = %d\n", flags.width);
	printf("4) Precision = %d\n", flags.precision);

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
			t_flags flags = get_flags((char *)++str);
			ft_print_flags(flags);
		}
		else
			count += ft_putchar1(*str++);
	}
	va_end(ap);
	return 0;
}

#include <stdio.h>
int main()
{
	char *str = "Hello";
//	printf("%.3d\n", 44);
	ft_printf("feqwfwe%------44.6d fewfwe\n", 123);
	printf("%11d44.6d", 123);
	return 0;
}