#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

void	ft_convert_c(va_list ap, int left_space_pad_len, int right_space_pad_len);
void	ft_convert_s(va_list ap, int precision, int left_space_pad_len, int left_zero_pad_len, int right_space_pad_len);

void	ft_convert_di(va_list ap, int precision, int left_space_pad_len, int left_zero_pad_len, int right_space_pad_len);
void	ft_convert_p(va_list ap, int left_space_pad_len, int right_space_pad_len);
void	ft_convert_u(va_list ap, int precision, int left_space_pad_len, int left_zero_pad_len, int right_space_pad_len);
void	ft_convert_xX(const char format_str, va_list ap);

int		ft_get_base_length(char *base);
int		ft_check_base(char *base);
void	ft_put_unsigned_nbr_base(unsigned long nbr, char *base);
void	ft_putnbr_base(int nbr, char *base);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr, char *base, int base_length);
void	ft_put_unsigned_nbr(unsigned int nb);
void	ft_put_unsigned_long_nbr(unsigned long nbr, char *base, unsigned long base_length);

int		pad_left_spaces(int left_space_pad_len, int item_len);
void	pad_left_zeros(int left_zero_pad_len, int item_len);
void	pad_right_spaces(int right_space_pad_len, int item_len);

int 	get_digits(const char *format_str, int *pos);
int 	ft_printf(const char *format_str, ...);

#endif