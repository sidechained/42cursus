#include <stdio.h>
#include "../2_printf/ft_printf_bonus.h"

// conversion: c s p d i u x X %
// TODO LIST:
// Instead of a decimal digit string one may write "*" or "*m$" (for some decimal integer m) to specify that the precision is given in the next argument, or in

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

	// test_print(" %p ", -1);
	// test_print(" %p ", 1);
	// test_print(" %p ", 15);
	// test_print(" %p ", 16);
	// test_print(" %p ", 17);
	// test_print(" %p %p ", LONG_MIN, LONG_MAX);
	// test_print(" %p %p ", INT_MIN, INT_MAX);
	// test_print(" %p %p ", ULONG_MAX, -ULONG_MAX);

	// test_print("%.s", "");
	// test_print(" %.1s", "");
	// test_print("%.1s ", "");
	// test_print(" %.s ", "");
	// test_print(" %.s ", "-");

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

	// test_print("%#x", 0);
	// test_print("%x", 0);
	// test_print("%#x", 100);
	// test_print("%#x", -100);
	// test_print("%x", 100);	
	// test_print("%##x", 100);
	// test_print("%d", 200); // without
	// test_print("% d", 200); // with
	// test_print("% d", -200); // with	
	// test_print("%  d", 200); // with 2 spaces only one space counted
	// test_print("%  d", -200); // with 2 spaces only one space counted	
	// test_print("% i", 0);
	// test_print("% i", -1);	
	// test_print("%012d", 452);
	// test_print("%0d", 452);
	// test_print("%+012d", 452); // DONE: plus flag should count as part of the left zero pad length
	// test_print("%+0d", 452);	
	// test_print("%-12d", 452);
	// test_print("%-d", 452);
	// test_print("%+-12d", 452); // DONE plus flag should count as part of the left zero pad length
	// test_print("%+-d", 452);	
	// test_print("%+-5d", 452);	
	// test_print("%.5d", 123456789);
	// test_print("%.15d", 123456789);
	// test_print("%.d", 2000); // (minimum number of digits)
	// test_print("%.10d", 200);
	// test_print("%.5d", 200);
	// test_print("%.10d", 200);
	// test_print("%.5d", 200);
	// test_print("%.4d", 200);
	// test_print("%.3d", 200);
	// test_print("%.2d", 200);
	// test_print("%.1d", 200);
	// test_print("%.0d", 200);

	// test_print("%.4d", 200);
	// test_print("%.3d", 200);
	// test_print("%.2d", 200);
	// test_print("%.1d", 200);
	// test_print("%.0d", 200);
	// test_print("%.-1d", 200);
	// TODO 

	// . (precision) is provided, but precision value is omitted (taken to be zero)
	// precision is taken to be zero, thats why the zero appears
	// you can't have the precision of a minus, so the string is output 'as is'
	// what happens in my code when a minus follows in precision?
	// print extract_integer gives '-12' printf("\nextracted: %i\n", ft_atoi(str));

	// - right pad blanks
	// test_print("%.d", 200);						
	// test_print("%+d", 0);	
	// test_print("%+d", -200);

	// + flag (signed conversion only i.e. d, i, p) OVERRIDES SPACE
	// printf("%d\n", 200);
	// printf("%+d\n", 200);
	// printf("%d\n", -200);
	// printf("%+d\n", -200); // does nothing as neg numbers print a sign anyway
	// printf("%+p\n", 0); // prints nil
	// printf("%+p\n", 200); // printf	
	// printf("%+p\n", -200);	

	// 	// MORE FLAGS TESTS
	// 	// test_print(" %p %p ", 0, 0);

	// 	// p flags
	// 	// '-' - all
	// 	// test_print("%-10d", 15);
	// 	// test_print("%-10i", 15);
	// 	// test_print("%-10u", 15);
	// 	test_print("%-10x", 15);
	// 	test_print("%-10X", 15);
	// 	test_print("%-10p", 15);
	// 	test_print("%-10c", 'c');

	// 	// '0' - di, u, xX only
	// 	// '.' - di, u, xX (minimum number of digits to appear), s(maximum number of characters to be printed)
	// 	// DONE (except does it apply to p?): ' ' '+' signed conversions only (i.e. di)
	// 	// DONE: '#' - x, x only	

	// // '#' nonzero result have "0x" prepended (x, x only)
	// printf("%#x\n", 0);
	// printf("%#x\n", 1);
	// ft_printf("%#x\n", 0);
	// ft_printf("%#x\n", 1);

	// printf("%x\n", 0);
	// printf("%x\n", 1);
	// printf("%##x\n", 1); // with 2 hashes only one counted

	// '0' 
	// only for d, i, u, x and X
	// printf("%09d", 1);
	// printf("%09d", 1);

	// OVERRIDES (TODO):

	return (0);
}