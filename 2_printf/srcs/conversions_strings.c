#include "conversions_strings.h"

void	ft_convert_c(va_list ap, int left_space_pad_len, int right_space_pad_len)
{
	char c;

	c = va_arg(ap, int); // char is promoted to int, so just using int here
	pad_left_spaces(left_space_pad_len, 1); // 1 = char length
	ft_putchar(c);
	pad_right_spaces(right_space_pad_len, 1);
}


void	ft_convert_s(va_list ap, int precision, int left_space_pad_len, int left_zero_pad_len, int right_space_pad_len)
{
	char *s;
	int s_len;
	
	s = va_arg(ap, char *);
	s = strdup(s);
	s[precision] = '\0';
	s_len = strlen(s);
	pad_left_spaces(left_space_pad_len, s_len);
	pad_left_zeros(left_zero_pad_len, s_len);
	ft_putstr(s);
	pad_right_spaces(right_space_pad_len, s_len);
}
