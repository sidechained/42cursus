#include "libft.h"

void  test_ft_memset(bool testmode, void *s, int c, size_t n)
{
	printf("Replacing first %zu bytes of \"%s\" with '%c'\n", n, s, c);
	printf("BEFORE:%s\n", s);
	if (testmode)
		memset(s, c, n);
	else
		ft_memset(s, c, n);
	printf("AFTER: %s\n", s);
}

void  tests_ft_memset(bool testmode)
{
	char s[50] = "CASH rules everything around me"; // can we do it with string literal as an argument
	test_ft_memset(testmode, s, '$', 4);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_memset(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_memset(false);
	}
	return 0;
}