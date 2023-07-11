#include <unistd.h>
#include <stdarg.h>

void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_digit(int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &hexadecimal[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int length = 0;

	va_list	pointer;
	va_start(pointer, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_digit(va_arg(pointer, int), 10, &length);
			else if (*format == 'x')
				put_digit(va_arg(pointer, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length);
}

#include <stdio.h>
#include <limits.h>

int main()
{
	// printf("%i ", ft_printf("%s\n", "toto\n"));
	// printf("%i ", ft_printf("Magic %s is %d\n", "number", 42));
	// printf("%i ", ft_printf("Hexadecimal for %d is %x\n", 42, 42));
	// printf("%i ", ft_printf(""));
	// printf("%i \n", ft_printf("Magic is %x\n", INT_MAX));
	// printf("%i \n", printf("Magic is %x\n", INT_MAX));
	printf("%i \n", ft_printf("Magic is %s\n", NULL));
	printf("%i \n", printf("Magic is %s\n", NULL));

}