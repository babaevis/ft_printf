#include <stdarg.h>
#include "libft.h"

typedef struct {
	int width;
	int zero;
	int precision;
	int minus;
	char type;
} t_flags;

int is_type(char c);
int check_zero_flag(const char *str);
int check_minus_flag(const char *str);
int check_width_flag(char *str, va_list list);
int check_precision_flag(char *str, va_list list);
int count_digits(int nb);
int handle_flags(va_list list, t_flags flags);
t_flags get_flags(char *str, va_list list);
int is_type(char c);
int ft_printf(const char *str, ...);