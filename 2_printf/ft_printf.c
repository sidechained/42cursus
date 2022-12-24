#include "ft_printf.h"

int ft_printf(const char *format_str, ...)
{
	int len;
	va_list ap;

	va_start(ap, format_str);
	len = ft_vprintf(format_str, ap);
	va_end(ap);
	return (len);
}

int ft_vprintf(const char *format_str, va_list ap)
{
	int pos;
	int len;

	pos = 0;
	len = 0;

	while(format_str[pos])
	{
		if (format_str[pos] == '%')
		{
			pos++;
			
			// conversions
			if (format_str[pos] == 'c')
			{
				pos++;
				len = ft_convert_c(ap, len);
			}

			if (format_str[pos] == 's')
			{
				pos++;
				len = ft_convert_s(ap, len);
			}

			if (format_str[pos] == 'd' || format_str[pos] == 'i')
			{
				pos++;
				len = ft_convert_di(ap, len);
			}

			if (format_str[pos] == 'p')
			{
				pos++;
				len = ft_convert_p(ap, len);
			}

			if (format_str[pos] == 'u')
			{
				pos++;
				len = ft_convert_u(ap, len);
			}

			if (format_str[pos] == 'x'|| format_str[pos] == 'X')
			{
				pos++;
				ft_convert_xX(format_str[pos], ap, len);
			}

		}
		else
		{
			write(1, &format_str[pos], 1);
			pos++;
			len++;
		}
	}
	return (len); // should return neg if error, but when does this happen?
}

int	ft_convert_c(va_list ap, int len)
{
	ft_putchar(va_arg(ap, int));
	return(len + 1);
}

int	ft_convert_s(va_list ap, int len)
{
	char *s;
	
	s = va_arg(ap, char *);
	ft_putstr(s);
	return(len + ft_strlen(s));
}

int	ft_convert_di(va_list ap, int len)
{
	char *di_str;

	di_str = ft_itoa(va_arg(ap, int));
	ft_putstr(di_str);
	return (len + ft_strlen(di_str));
}

int	ft_convert_p(va_list ap, int len)
{
	write(2, "0x", 2);
	len = len + 2 + ft_put_unsigned_nbr_base((unsigned long)va_arg(ap, char *), "0123456789abcdef");
	return (len);
}

int	ft_convert_u(va_list ap, int len)
{
	char *u_str;

	u_str = ft_itoa(va_arg(ap, unsigned int));
	ft_putstr(u_str);
	return (len + ft_strlen(u_str));
}

int	ft_convert_xX(const char format_str, va_list ap, int len)
{
	char *base;

	if (format_str == 'x')
		base = "0123456789abcdef";
	if (format_str == 'X')
		base = "0123456789ABCDEF";
	len = len + ft_put_unsigned_nbr_base(va_arg(ap, unsigned int), base); // hex also comes in as unsigned int
	return (len);
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

int	ft_get_base_len(char *base)
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_unsigned_long_nbr(unsigned long nbr, char *base, unsigned long base_len, int *result_len)
{
 	if (nbr < base_len)
	{
		ft_putchar(base[nbr]);
		(*result_len)++;
		return;
	}
	ft_put_unsigned_long_nbr(nbr / base_len, base, base_len, result_len);
	ft_put_unsigned_long_nbr(nbr % base_len, base, base_len, result_len);
}

int	ft_put_unsigned_nbr_base(unsigned long nbr, char *base)
{
	unsigned long	base_len;
	int				result_len;

	base_len = ft_get_base_len(base);
	if (base_len <= 1)
		return (-1); // TODO/HANDLE
	if (ft_check_base(base) == 0)
		return (-1); // TODO/HANDLE
	result_len = 0;
	ft_put_unsigned_long_nbr(nbr, base, base_len, &result_len);
	return (result_len);
}
