#include <stdarg.h>
#include "libft.h"

typedef struct {
	int width;
	int zero;
	int precision;
	int minus;
	int asterisk;
	char type;
} t_flags;

int count_digits(int nb);
int handle_flags(va_list list, t_flags flags);
t_flags get_flags(char *str, va_list list);
int is_type(char c);
int ft_printf(const char *str, ...);