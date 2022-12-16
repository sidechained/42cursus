#include <stdio.h>
#include "libftprintf.h"

// ERRORS:
// my ft_printf does not return number of characters printed (tests should test returns not just what is printed)

// writing tests:
// how to compare output?
// how to write a generic test function when we don't know what or how many arguments there will be
// (we only know that first is the string to parse, and subsequent are args to print and the number must match)

int main()
{
	int n;
	n = ft_printf("|%-5s|%-5s|\n", "one", "two");
	printf("%i\n", n);
	// n = printf("|%-5s|%-5s|\n", "one", "two");
	// ft_printf("|%-15s|%-10s|\n", "one", "two");
	// printf("|%-15s|%-10s|\n", "one", "two");
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
	// // Q: can it handle two asterisks?
	// ft_printf("%.*s\n", 3, "abcdef");
	// printf("%.*s\n", 3, "abcdef"); // takes first argument as width (precision)
	// // Other Types:
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