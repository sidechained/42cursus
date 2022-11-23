#include "libft.h"

void test_ft_substr(char const *s, unsigned int start, size_t len)
{
	char *res;
	res = ft_substr(s, start, len);
	printf("string \"%s\", start %i, max length %zu.\nRESULT: \"%s\"\n", s, start, len, res);
}

int	main()
{
	printf("TESTING: substr part of string from start: ");
	test_ft_substr("TestingTing", 0, 5);
	printf("TESTING: substr part of string from middle: ");
	test_ft_substr("TestingTing", 5, 3);
	printf("TESTING: substr part of string up to end: ");
	test_ft_substr("TestingTing", 6, 5);
	printf("TESTING: substr whole string from beginning: ");
	test_ft_substr("TestingTing", 0, 11);
	printf("TESTING: substr whole string +1 from beginning (is this expected?): ");
	test_ft_substr("TestingTing", 0, 12);
	printf("TESTING: substr with length greater than string length [from start]: ");
	test_ft_substr("TestingTing", 0, 20);
	printf("TESTING: substr with length greater than string length [from middle]: ");
	test_ft_substr("TestingTing", 7, 20);
	printf("TESTING: substr with length and start greater than string length: ");
	test_ft_substr("TestingTing", 0, 20);
	printf("TESTING: start and length : ");
	test_ft_substr("TestingTing", 0, 0);
	printf("TESTING: negative length: ");
	test_ft_substr("TestingTing", 0, -5);
	printf("TESTING: negative start index: ");
	test_ft_substr("TestingTing", -2, 11);

	return (0);
}
