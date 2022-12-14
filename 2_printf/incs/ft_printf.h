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

int get_digits(const char *format_str, int *pos);
int ft_printf(const char *format_str, ...);

#endif