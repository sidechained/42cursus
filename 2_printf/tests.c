#include <stdio.h>
#include "ft_printf.h"

void	test_print(const char *format_str, ...)
{
	int n;
	va_list ap;
	va_start(ap, format_str);
	printf("PRINTF:\n");
	n = vprintf(format_str, ap);
	printf(" length:%i\n", n);
	va_end(ap);
	va_start(ap, format_str);
	printf("FT_PRINTF:\n");
	n = ft_vprintf(format_str, ap);
	printf(" length:%i\n\n", n);
	va_end(ap);
}

// no padding, no precision, for now

int main()
{
	// character tests:
	// test_print("%c", 'a');
	// test_print("z%cz", 'a');
	// test_print("%c%c%c", 'a', 'b', 'c');		
	// test_print("zzz%cy%cxx%cwww", 'a', 'b', 'c');

	// string tests:
	// test_print("%s", "aa");	
	// test_print("%s%s", "abc", "def");	
	// test_print("zz%szz", "aa");	
	// test_print("z%syy%sxx", "abc", "def");

	// digit/integer tests:
	// test_print("%d", 0);
	// test_print("%i", 123);
	// test_print("%d%d", 123, 456);
	// test_print("zz%iyy%ixx", 123, 456);

	// pointer tests
	// char *test = "test";
	// test_print("%p", &test);

	// unsigned decimal tests
	// test_print("%u", 0);
	// test_print("%u", 123);
	// test_print("%u%u", 123, 456);
	// test_print("zz%uyy%uxx", 123, 456);
	// test_print("%u", +123);
	// test_print("%u", -123);	// FAIL!

	// unsigned hexadecimal tests
	test_print("hello %x\n", 151515);
	// test_print("hello %X\n", 151515);
	// test_print("hello %*x\n", 20, 151515); // lengthens
	// test_print("hello %*x\n", 5, 151515); // but does not truncate	

	// test_print("|%s|%s|\n", "one", "two");
	// test_print("|%-5s|%-5s|\n", "one", "two");
	// test_print("|%-10s|%-10s|\n", "one", "two");
	// test_print("|%-15s|%-10s|\n", "one", "two");
	// test_print("|%05d|%05d|\n", 100, 200);
	// test_print("|%.3s|%.2s|\n", "test", "string");
	// test_print("|%.2d|%.1d|\n", 100, 200);
	// test_print( "|%*5d|%*2d|\n", 100, 200);
	// test_print("%*d\n", 5, 10); // * takes first argument as width
	// test_print("%*d\n", 5, 100000); // * takes first argument as width
	// test_print("%*s\n", 5, "teststring"); // Q: can it handle two asterisks?
	// test_print("%.*s\n", 3, "abcdef");
	// test_print("%*c\n", 5, 't');
	// test_print("%*c\n", 5, 't');
	// test_print("%-15ctest\n", 't');
	// test_print("hello %p\n", &test);	
	// test_print("hello %*p\n", 20, &test); // lengthens
	// test_print("hello %*p\n", 5, &test); // but does not truncate
	// test_print("hello %-25ptest\n", &test); // also works
	// test_print("hello %x\n", 151515);	
	// test_print("hello %X\n", 151515);
	// test_print("hello %*x\n", 20, 151515); // lengthens
	// test_print("hello %*x\n", 5, 151515); // but does not truncate
	// test_print("hello %-25xtest\n", 151515); // also works
	return (0);
}