#include "libft.h"

void	test_ft_bzero(bool testmode, void *s, size_t n)
{
	printf("BEFORE:\"%s\"\n", s);
	if (testmode)
		bzero(s, n);
	else
		ft_bzero(s, n);
	printf("AFTER: \"%s\"\n", s);
}

void	tests_ft_bzero(bool testmode)
{
	char s[50] = "This should be erased by bzero...";
	test_ft_bzero(testmode, s, 10);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_bzero(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_bzero(false);
	}
	return 0;
}