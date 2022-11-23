#include "libft.h"

void test_ft_substr(char const *s, unsigned int start, size_t len)
{
	char *res;
	res = ft_substr(s, start, len);
	printf("Substring of \"%s\" at start %i of length %zu. RESULT: \"%s\"\n", s, start, len, res);
}

int	main()
{
	test_ft_substr("TestingTing", 0, 11);
	test_ft_substr("TestingTing", 0, 11);
	test_ft_substr("TestingTing", 0, 5);
	test_ft_substr("TestingTing", 4, 5);
	test_ft_substr("TestingTing", 6, 5);
	test_ft_substr("TestingTing", 0, 20);
	test_ft_substr("TestingTing", 4, 20);
	test_ft_substr("TestingTing", 0, 20);
	test_ft_substr("TestingTing", 0, 0);
	test_ft_substr("TestingTing", 0, -5);
	test_ft_substr("TestingTing", -2, 11);
	printf("is this expected:\n");	
	test_ft_substr("TestingTing", 0, 12);
	return (0);
}
