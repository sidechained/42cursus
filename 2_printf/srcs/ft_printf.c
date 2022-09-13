#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#include "ft_printf.h"

int get_digits(const char *format_str, int *pos)
{
	//extract digits, convert to int and return:
	char *digits_str;
	int digits_int;
	int digit_len;
	int i;

	++*pos;
	digit_len = 0;
	while(isdigit(format_str[*pos + digit_len]))
	 	digit_len++;
	digits_str = strdup(&format_str[*pos]);
	digits_str[digit_len] = '\0';
	i = 0;
	while(i < digit_len)
	{
		i++;
		++*pos;
	}
	digits_int = atoi(digits_str);
	return(digits_int);
}

int ft_printf(const char *format_str, ...)
{
	va_list ap;
	
	int pos;
	int left_space_pad_len;	
	int right_space_pad_len;
	int left_zero_pad_len;
	int precision;

	pos = 0;

	va_start(ap, format_str);
	while(format_str[pos])
	{
		if (format_str[pos] == '%')
		{
			pos++;
			
			// -1 here means they are unset
			left_space_pad_len = -1;
			right_space_pad_len = -1;
			left_zero_pad_len = -1;
			precision = -1;

			// flags
			if (format_str[pos] == '-')
				right_space_pad_len = get_digits(format_str, &pos);
			if (format_str[pos] == '0')
				left_zero_pad_len = get_digits(format_str, &pos);
			if (format_str[pos] == '.')
				precision = get_digits(format_str, &pos);
			if (format_str[pos] == '*')
			{
				pos++;
				left_space_pad_len = va_arg(ap, int);
			}

			// conversions
			if (format_str[pos] == 'c')
			{
				pos++;
				ft_convert_c(ap, left_space_pad_len, right_space_pad_len);
			}

			if (format_str[pos] == 's')
			{
				pos++;
				ft_convert_s(ap, precision, left_space_pad_len, left_zero_pad_len, right_space_pad_len);
			}

			if (format_str[pos] == 'd' || format_str[pos] == 'i')
			{
				pos++;
				ft_convert_di(ap, precision, left_space_pad_len, left_zero_pad_len, right_space_pad_len);
			}

			// not quite working
			if (format_str[pos] == 'p')
			{
				pos++;
				ft_convert_p(ap, left_space_pad_len, right_space_pad_len);
			}

			if (format_str[pos] == 'u')
			{
				pos++;
				ft_convert_u(ap, precision, left_space_pad_len, left_zero_pad_len, right_space_pad_len);
			}

			if (format_str[pos] == 'x'|| format_str[pos] == 'X')
			{
				pos++;
				ft_convert_xX(format_str[pos], ap);
			}

		}
		else
		{
			write(1, &format_str[pos], 1);
			pos++;
		}
	}
	va_end(ap);
	return (1);
}