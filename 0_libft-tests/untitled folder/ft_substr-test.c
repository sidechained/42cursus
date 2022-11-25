#include "../0_libft/inc/libft.h"

void test_ft_substr(char const *s, unsigned int start, size_t len)
{
	char *res;
	res = ft_substr(s, start, len);
	printf("- string \"%s\", start %i, max length %zu.\nRESULT = \"%s\"\n\n", s, start, len, res);
}

int	main()
{
	printf("TEST: substr part of string from start...\n");
	test_ft_substr("TestingTing", 0, 5);
	printf("TEST: substr part of string from middle...\n");
	test_ft_substr("TestingTing", 5, 3);
	printf("TEST: substr part of string up to end...\n");
	test_ft_substr("TestingTing", 6, 5);
	printf("TEST: substr whole string from beginning...\n");
	test_ft_substr("TestingTing", 0, 11);
	printf("TEST: substr (whole string +1) from beginning (is this expected?)...\n");
	test_ft_substr("TestingTing", 0, 12);
	printf("TEST: substr with length greater than string length [from start]...\n");
	test_ft_substr("TestingTing", 0, 20);
	printf("TEST: substr with length greater than string length [from middle]...\n");
	test_ft_substr("TestingTing", 7, 20);
	printf("TEST: substr with length and start greater than string length...\n");
	test_ft_substr("TestingTing", 0, 20);
	printf("TEST: start and length ...\n");
	test_ft_substr("TestingTing", 0, 0);
	printf("TEST: negative length...\n");
	test_ft_substr("TestingTing", 0, -5);
	printf("TEST: negative start index...\n");
	test_ft_substr("TestingTing", -2, 11);
	return (0);
}
