#include "../0_libft/inc/libft.h"

void	test_ft_bzero(bool testmode, char *s, size_t n)
{
	printf("Zero-ing out %zu bytes of \"%s\"\n", n, s);
	int len = strlen(s);
	if (testmode)
		bzero(s, n);
	else
		ft_bzero(s, n);
	printf("RESULT = \"");
	int i = 0;
	while(i < len)
	{
		if (s[i] == 0)
			printf("0");
		else
			printf("%c", s[i]);
		i++;
	}
	printf("\"\n\n");
}

void	tests_ft_bzero(bool testmode)
{
	// standard case:
	char s[] = "Part of this should be replaced by bzero...";
	test_ft_bzero(testmode, s, 10);

	// size greater than length of string:
	char t[] = "All of this should be replaced by bzero...";
	test_ft_bzero(testmode, t, 42); 

	// size of zero (string should remain the same):
	char u[] = "This should *not* be replaced by bzero...";
	test_ft_bzero(testmode, u, 0);
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