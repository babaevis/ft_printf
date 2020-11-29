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
	printf("5) Type = %c\n", flags.type);

}

int parse_str(const char *str, va_list list)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			t_flags flags = get_flags((char *)++str, list);
			//ft_print_flags(flags);
			count += handle_flags(list, flags);
			while (!is_type(*str) && *str)
				str++;
			if(is_type(*str))
				str++;
		}
		else
			count += ft_putchar1(*str++);
	}
	return count;
}

int ft_printf(const char *str, ...)
{
	va_list list;
	va_start(list, str);
	int count;

	count = parse_str(str, list);
	va_end(list);
	ft_putchar1('\n');
	return count;
}

int main()
{
	char *str = "%*.*c\n";
	char num = 0;
	int width = -7;
	int precision = 3;
	printf("%d | %d", ft_printf(str, width,precision, 0), printf(str, width,precision, 0));
//	printf(str, width,precision, num);
	return 0;
}