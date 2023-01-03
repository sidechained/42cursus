#include <stdio.h>
#include "../2_printf/ft_printf.h"

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

int main()
{
	// percentage tests
	// test_print("%");
	// test_print("%%");
	// test_print("%%%");
	// test_print("%%%%");
	// test_print("%%%%%");
	// test_print(" %% % %% % %%% %%%% %%%%%");

	// character tests:
	// test_print("%c", 'a');
	// test_print("z%cz", 'a');
	// test_print("%c%c%c", 'a', 'b', 'c');		
	// test_print("zzz%cy%cxx%cwww", 'a', 'b', 'c');
	// test_print("%c", 112);
	// test_print("%c", 270);	
	// test_print("%c", 1224832843);	
	// test_print("%c %c %c", 1224832, 1224832843, 23293219329);
	// test_print("%c", ''); // warning: empty character constant

	// string tests:
	// test_print("%s", "aa");	
	// test_print("%s%s", "abc", "def");	
	// test_print("zz%szz", "aa");	
	// test_print("z%syy%sxx", "abc", "def");
	// test_print("z%syy%sxx", NULL, "def");
	// test_print("%s", NULL);
	// test_print("%s %s %s", NULL, NULL, NULL);
	// test_print("%s %s %s", NULL, "one", NULL);
	// test_print("%s %s %s", NULL, -200, NULL); // causes printf segfault (also in ft_print, but mine functions prints (null) first))
	// test_print("%s", "");	

	// digit/integer tests:
	// test_print("%d", 0);
	// test_print("%i", 123);
	// test_print("%d%d", 123, 456);
	// test_print("zz%iyy%ixx", 123, 456);

	// pointer tests
	// char *test = "test";
	// char *this = "this";
	// test_print("%p", &test);
	// test_print("%p %p", &test, &test);
	// test_print("zz %p yy %p xx", &test, &this);
	// char *nest = NULL;
	// test_print("%p", &nest);

	test_print(" %p ", -1);
	test_print(" %p ", 1);
	test_print(" %p ", 15);
	test_print(" %p ", 16);
	test_print(" %p ", 17);
	test_print(" %p %p ", LONG_MIN, LONG_MAX);
	test_print(" %p %p ", INT_MIN, INT_MAX);
	test_print(" %p %p ", ULONG_MAX, -ULONG_MAX);
	test_print(" %p %p ", 0, 0);

	// unsigned decimal tests
	// test_print("%u", 0);
	// test_print("%u", 123);
	// test_print("%u%u", 123, 456);
	// test_print("zz%uyy%uxx", 123, 456);
	// test_print("%u", +123);
	// test_print("%u", -122);
	// test_print("%u", 4294967295);

	// unsigned hexadecimal tests
	// test_print("hello %x\n", 151515);
	// test_print("hello %X\n", 151515);
	// test_print("hello %x\n", 151515);

	// mixed tests:
	// char *mixed = "789";
	// test_print("%c%s%d%i%p%u%x%X", 'a', "bb", 123, 456, &mixed, 789, 151515, 101010);
	// test_print("%c%s%d%i%p%u%x%X", NULL, "bb", 123, 456, &mixed, 789, 151515, 101010);
	// test_print("%c%s%d%i%p%u%x%X", NULL, "bb", NULL, 456, &mixed, NULL, 151515, NULL);

	// NULL and empty string tests
	// test_print("%c", NULL);
	// test_print(NULL, 'c');
	// test_print(NULL, NULL);
	// test_print("%c %c %c", 'a', NULL, 'c');
	// test_print("", 'a');

	// no args don't match number of %'s in format str
	// test_print("%c%c%c");
	// test_print("%c%c%c", 'a');
	// test_print("%c %c %c", 'a', 'b');
	// test_print("%c", 'a', 'b', 'c');
	// test_print("%c", 'a', 'b');
	// test_print("%c", 'a', NULL, 'c');
	// test_print("%c", NULL, NULL, 'c');

	return (0);
}

// flags tests (precision, padding etc)
// test_print("hello %*x\n", 20, 151515); // lengthens
// test_print("hello %*x\n", 5, 151515); // but does not truncate	
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
// test_print("hello %*p\n", 20, &test); // lengthens
// test_print("hello %*p\n", 5, &test); // but does not truncate
// test_print("hello %-25ptest\n", &test); // also works
// test_print("hello %*x\n", 20, 151515); // lengthens
// test_print("hello %*x\n", 5, 151515); // but does not truncate
// test_print("hello %-25xtest\n", 151515); // also works
