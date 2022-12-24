#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

int		ft_convert_c(va_list ap, int len);
int		ft_convert_s(va_list ap, int right_space_pad_len);
int		ft_convert_di(va_list ap, int len);
int		ft_convert_p(va_list ap, int len);
int		ft_convert_u(va_list ap, int len);
int		ft_convert_xX(const char format_str, va_list ap, int len);

int		ft_get_base_length(char *base);
int		ft_check_base(char *base);

void	ft_putchar(char c);
void	ft_putstr(char *str);

int		ft_put_unsigned_nbr_base(unsigned long nbr, char *base);
void	ft_put_unsigned_long_nbr(unsigned long nbr, char *base, unsigned long base_length, int *len);

int 	ft_printf(const char *format_str, ...);
int 	ft_vprintf(const char *format_str, va_list ap);

#endif