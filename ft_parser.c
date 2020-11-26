#include "ft_printf.h"

int is_type(char c)
{
	return (c == 'd' || c == 'x' || c == 'X' || c == 'u'
	|| c == 'p' || c == 'i' || c == 's');
}

t_types init_types(void)
{
	t_types types;

	types.X = 0;
	types.c = 0;
	types.d = 0;
	types.i = 0;
	types.p = 0;
	types.s = 0;
	types.u = 0;
	types.x = 0;
	return types;
}

t_types set_type(char c)
{
	t_types types;

	types = init_types();
	if(c == 'd')
		types.d = 1;
	else if(c == 'x')
		types.x = 1;
	else if(c == 'X')
		types.X = 1;
	else if(c == 'i')
		types.i = 1;
	else if(c == 'u')
		types.u = 1;
	else if(c == 'c')
		types.c = 1;
	else if(c == 's')
		types.s = 1;
	return types;
}

int check_zero_flag(const char *str)
{
	if (str[0] == '0')
		return 1;
	return 0;
}

int check_minus_flag(const char *str)
{
	if(*str == '-')
		return 1;
	return 0;
}

int check_precision_flag(char *str)
{
	if (*str == '.')
		return (ft_atoi(str+1));
	return (0);
}

t_flags parse_format(char *str)
{
	int i;
	t_flags flags;

	i = 0;
	flags.zero = check_zero_flag(str);
	flags.minus = check_minus_flag(str);
	while (check_minus_flag(str))
		str++;
	flags.width = ft_atoi(str);
	while(ft_isdigit(*str))
		str++;
	flags.precision = check_precision_flag(str);
	while(*str && !is_type(*str))
	{
		str++;
		if(is_type(*str))
			flags.types = set_type(*str);
	}
	return flags;
}

t_flags get_flags(char *str)
{
	t_flags flags;

	flags = parse_format(str);
	return flags;
}