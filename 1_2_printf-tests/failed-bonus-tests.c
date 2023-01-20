#include <stdio.h>
#include "../2_printf/ft_printf_bonus.h"

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

// an extra test
// test_print(" 08.3d", -8375);
// next try: https://github.com/gavinfielder/pft
int main()
{
	test_print(" 08.3d", -8375);
	// For /nfs/homes/gbooth/francinette/tests/test_printf/test_printfTester/tests/c_test.cpp:
	// 29: 	TEST(5, 
	test_print(" %c %c %c ", '0', 0, '1');
	// 32: 	TEST(8, 
	test_print(" %c %c %c ", '2', '1', 0);
	// 33: 	TEST(9, 
	test_print(" %c %c %c ", 0, '1', '2');

	// For /nfs/homes/gbooth/francinette/tests/test_printf/test_printfTester/tests/mix_test.cpp:
	// 25: 	TEST(1, 
	test_print("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);

	// For /nfs/homes/gbooth/francinette/tests/test_printf/test_printfTester/tests/minus_test.cpp:
	// 29: 	TEST(5, 
	test_print(" %-1c %-2c %-3c ", '0', 0, '1');
	// 32: 	TEST(8, 
	test_print(" %-1c %-2c %-3c ", '2', '1', 0);
	// 33: 	TEST(9, 
	test_print(" %-1c %-2c %-3c ", 0, '1', '2');
	// 35: 	TEST(10, 
	// test_print("%1s", "");
	// 36: 	TEST(11, 
	// test_print("%-1s", "");
	// 37: 	TEST(12, 
	// test_print(" %-2s", "");
	// 38: 	TEST(13, 
	// test_print("%-3s ", "");
	// 41: 	TEST(16, 
	test_print(" %-1s %-2s ", "", "-");
	// 42: 	TEST(17, 
	// test_print(" %-3s %-4s ", " - ", "");
	// 43: 	TEST(18, 
	// test_print(" %-2s %-3s %-4s %-5s ", " - ", "", "4", "");
	// 44: 	TEST(19, 
	// test_print(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");
	// 46: 	TEST(20, 
	// test_print(" %2p ", -1);

	// For /nfs/homes/gbooth/francinette/tests/test_printf/test_printfTester/tests/space_test.cpp:
	// 26: 	TEST(2, 
	// test_print(" % 1s", "");
	// 27: 	TEST(3, 
	// test_print("% 1s ", "");


}