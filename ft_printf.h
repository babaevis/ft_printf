#include <stdarg.h>
#include "libft.h"

typedef struct {
	int x;
	int X;
	int p;
	int i;
	int d;
	int c;
	int s;
	int u;
}t_types;

typedef struct {
	int width;
	int zero;
	int precision;
	int minus;
	int asterisk;
	t_types types;
} t_flags;


t_flags get_flags(char *str);
int is_type(char c);
int ft_printf(const char *str, ...);