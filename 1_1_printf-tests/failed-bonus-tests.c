#include <stdio.h>
#include "../1_1_printf/ft_printf.h"

void	test_print(const char *format_str, ...)
{
	int n;
	va_list ap;

	va_start(ap, format_str);
	printf("PRINTF:		\"");
	n = vprintf(format_str, ap);
	printf("\"	(length:%i)\n", n);
	va_end(ap);
	va_start(ap, format_str);
	printf("FT_PRINTF:	\"");
	fflush(stdout);
	n = ft_vprintf(format_str, ap);
	printf("\"	(length:%i)\n\n", n);
	va_end(ap);
}

int main()
{
	// all done!
}