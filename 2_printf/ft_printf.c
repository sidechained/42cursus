#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

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

// the following used by u conversion:

void	ft_put_unsigned_nbr(unsigned int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_put_unsigned_nbr(nb / 10);
		ft_put_unsigned_nbr(nb % 10);
	}
}

// the following used by p conversion:

int	ft_get_base_length(char *base)
{
	int	l;

	l = 0;
	while (base[l] != '\0')
		l++;
	return (l);
}

// check if base:empty or size 1, has dup char, has +/-/whitespace
int	ft_check_base(char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v')
			return (0);
		count = 0;
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j++])
			{
				count++;
				if (count > 1)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

void	ft_put_unsigned_long_nbr(unsigned long nbr, char *base, unsigned long base_length)
{
	unsigned long	i;

 	if (nbr <= base_length)
	{	
		i = 0;
		while (i < nbr)
		{
			i++;
		}
		ft_putchar(base[i]);
	}
	else
	{
		ft_put_unsigned_long_nbr(nbr / base_length, base, base_length);
		ft_put_unsigned_long_nbr(nbr % base_length, base, base_length);
	}
}

void	ft_put_unsigned_nbr_base(unsigned long nbr, char *base)
{
	unsigned long	base_length;

	base_length = ft_get_base_length(base);
	if (base_length <= 1)
		return ;
	if (ft_check_base(base) == 0)
		return ;
	ft_put_unsigned_long_nbr(nbr, base, base_length);
}

// used in xX conversion:

void	ft_putnbr(int nbr, char *base, int base_length)
{
	int	i;

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		ft_putnbr(nbr, base, base_length);
	}
	else if (nbr <= base_length)
	{	
		i = 0;
		while (i < nbr)
		{
			i++;
		}
		ft_putchar(base[i]);
	}
	else
	{
		ft_putnbr(nbr / base_length, base, base_length);
		ft_putnbr(nbr % base_length, base, base_length);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;

	base_length = ft_get_base_length(base);
	if (nbr == -2147483648)
		return ;
	if (base_length <= 1)
		return ;
	if (ft_check_base(base) == 0)
		return ;
	ft_putnbr(nbr, base, base_length);
}

// PADDING FUNCTIONS

int		pad_left_spaces(int left_space_pad_len, int item_len)
{
	int num_left_spaces_to_pad;
	int i;

	if (left_space_pad_len > item_len)
	// strings are padded if the pad length is longer than string length
	// but pad length is NOT treated as precision when it's shorter that string length
	{
		num_left_spaces_to_pad = left_space_pad_len - item_len;
		i = 0;
		while(i < num_left_spaces_to_pad)
		{
			ft_putchar(' ');
			i++;
		}
		return (0);
	}
	else
		return (1);
}

void	pad_left_zeros(int left_zero_pad_len, int item_len)
{
	int num_left_zeros_to_pad;
	int i;

	num_left_zeros_to_pad = left_zero_pad_len - item_len;
	i = 0;
	while(i < num_left_zeros_to_pad)
	{
		ft_putchar('0');
		i++;
	}
}

void	pad_right_spaces(int right_space_pad_len, int item_len)
{
	int num_right_spaces_to_pad;
	int i;

	num_right_spaces_to_pad = right_space_pad_len - item_len;
	i = 0;
	while(i < num_right_spaces_to_pad)
	{
		ft_putchar(' ');
		i++;
	}
}

// CONVERSIONS

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

void	ft_convert_di(va_list ap, int precision, int left_space_pad_len, int left_zero_pad_len, int right_space_pad_len)
{
	int di;
	int di_len;
	char di_str[100]; // how do avoid this?
	int treat_as_precision;

	di = va_arg(ap, int);
	sprintf(di_str, "%d", di);
	if (precision != -1)
		di_str[precision] = '\0';
	di_len = strlen(di_str);
	treat_as_precision = pad_left_spaces(left_space_pad_len, di_len);
	if (treat_as_precision == 1) // use true?!
		di_str[left_space_pad_len+1] = '\0'; // why +1?
	pad_left_zeros(left_zero_pad_len, di_len);
	ft_putstr(di_str);
	pad_right_spaces(right_space_pad_len, di_len);
}

void	ft_convert_p(va_list ap, int left_space_pad_len, int right_space_pad_len)
// p The void * pointer argument is printed in hexadecimal (as if by `%#x' or `%#lx').
{
	void *p;
	char *base;
	int p_len;

	base = "0123456789abcdef";
	p = va_arg(ap, char *);
	p = strdup(p);
	p_len = strlen(p);

	pad_left_spaces(left_space_pad_len, p_len);
	write(2, "0x", 2);
	ft_put_unsigned_nbr_base((unsigned long)p, base);
	pad_right_spaces(right_space_pad_len, p_len);
}

void	ft_convert_u(va_list ap, int precision, int left_space_pad_len, int left_zero_pad_len, int right_space_pad_len)
{
	unsigned int u;

	int u_len;
	char u_str[100]; // how do avoid this?
	int treat_as_precision;

	u = va_arg(ap, unsigned int);

	sprintf(u_str, "%d", u);
	if (precision != -1)
		u_str[precision] = '\0';
	u_len = strlen(u_str);
	treat_as_precision = pad_left_spaces(left_space_pad_len, u_len);
	if (treat_as_precision == 1)
		u_str[left_space_pad_len+1] = '\0'; // why +1?
	pad_left_zeros(left_zero_pad_len, u_len);
	ft_put_unsigned_nbr(u);
	pad_right_spaces(right_space_pad_len, u_len);
}

void	ft_convert_xX(const char format_str, va_list ap)
{
	unsigned int xX;
	char *base;
	
	printf("\n\nfstr:%c\n\n", format_str);

	if (format_str == 'x')
	{
		printf("getshere");
		base = "0123456789abcdef";
	}
	if (format_str == 'X')
	{
		printf("getshere");
		base = "0123456789ABCDEF";
	}

	printf("\n\nbase:%s\n\n", base);
	xX = va_arg(ap, unsigned int); // hex also comes in as unsigned int
	ft_putnbr_base(xX, base);
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

int main()
{
	char test;
	test = 'c';
	ft_printf("|%-5s|%-5s|\n", "one", "two");
	printf("|%-5s|%-5s|\n", "one", "two");
	ft_printf("|%-15s|%-10s|\n", "one", "two");
	printf("|%-15s|%-10s|\n", "one", "two");
	// ft_printf("|%05d|%05d|\n", 100, 200);
	// printf("|%05d|%05d|\n", 100, 200);
	// ft_printf("|%.3s|%.2s|\n", "test", "string");
	// printf("|%.3s|%.2s|\n", "test", "string");
	// ft_printf("|%.2d|%.1d|\n", 100, 200);
	// printf("|%.2d|%.1d|\n", 100, 200);
	// ft_printf( "|%*5d|%*2d|\n", 100, 200);
	// printf( "|%*5d|%*2d|\n", 100, 200);	
	// ft_printf("%*d\n", 5, 10); // * takes first argument as width
	// printf("%*d\n", 5, 10); // * takes first argument as width
	// ft_printf("%*d\n", 5, 100000); // * takes first argument as width
	// printf("%*d\n", 5, 100000); // * takes first argument as width
	// ft_printf("%*s\n", 5, "teststring");
	// printf("%*s\n", 5, "teststring");
	// Q: can it handle two asterisks?
	// ft_printf("%.*s\n", 3, "abcdef");
	// printf("%.*s\n", 3, "abcdef"); // takes first argument as width (precision)
	// Other Types:
	// ft_printf("%*c\n", 5, 't');
	// printf("%*c\n", 5, 't');
	// printf("%-15ctest\n", 't');
	// ft_printf("%*c\n", 5, 't');
	// ft_printf("%-15ctest\n", 't');

	// printf("%*c\n", 5, 't');
	// printf("%-15ctest\n", 't');
	// printf("hello %p\n", &test);	
	// printf("hello %*p\n", 20, &test); // lengthens
	// printf("hello %*p\n", 5, &test); // but does not truncate
	// printf("hello %-25ptest\n", &test); // also works
	// printf("\n\n");
	// ft_printf("hello %p\n", &test);	
	// ft_printf("hello %*p\n", 20, &test); // lengthens
	// ft_printf("hello %*p\n", 5, &test); // but does not truncate
	// ft_printf("hello %-25ptest\n", &test); // also works
	// ft_printf("hello %x\n", 151515);
	// ft_printf("hello %X\n", 151515);
	// printf("hello %x\n", 151515);
	// printf("hello %X\n", 151515);
	// printf("hello %x\n", 151515);
	// printf("hello %*x\n", 20, 151515); // lengthens
	// printf("hello %*x\n", 5, 151515); // but does not truncate
	// printf("hello %-25xtest\n", 151515); // also works
	// printf("\n\n");
	// ft_printf("hello %x\n", 151515);	
	// ft_printf("hello %*x\n", 20, 151515); // lengthens
	// ft_printf("hello %*x\n", 5, 151515); // but does not truncate
	// ft_printf("hello %-25xtest\n", 151515); // also works

	return (0);
}