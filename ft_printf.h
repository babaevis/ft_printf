#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct {
	int width;
	int zero;
	int precision;
	int minus;
	char type;
} t_flags;

int	handle_percent(t_flags flags);
int count_unsigned_digits(unsigned int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		pf_putchar(char c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
int		handle_pointer(va_list list, t_flags flags);
char		*ft_unsigned_itoa(unsigned int n);
int handle_unsigned(va_list list, t_flags flags);
int handle_hex(va_list list, t_flags flags);
int handle_char(va_list list, t_flags flags);
int handle_str(va_list list, t_flags flags);
int handle_int(va_list list, t_flags flags);
int pf_putstr(char *str);
int	pf_putnbr(int nb);
int is_type(char c);
int check_zero_flag(const char *str);
int check_minus_flag(const char *str);
int check_width_flag(char *str, va_list list);
int check_precision_flag(char *str, va_list list);
int count_digits(int nb);
int handle_flags(va_list list, t_flags flags);
t_flags get_flags(char *str, va_list list);
int ft_printf(const char *str, ...);
#endif