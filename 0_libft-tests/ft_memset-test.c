#include "../0_libft/libft.h"
#include <stdio.h>

void  test_ft_memset(bool testmode, void *s, int c, size_t n)
{
	void *t;
	printf("Replacing first %zu bytes of \"%s\" with '%c'\n", n, (char *)s, c);
	printf("BEFORE:%s\n", (char *)s);
	if (testmode)
		t = memset(s, c, n);
	else
		t = ft_memset(s, c, n);
	printf("AFTER: %s\n\n", (char *)t);
}

void  tests_ft_memset(bool testmode)
{	
	char s[] = "CASH rules everything around me";
	test_ft_memset(testmode, s, '$', 4);
	char t[] = "CASH rules everything around me";
	test_ft_memset(testmode, t, '$', 31);
	char u[] = "CASH rules everything around me";
	test_ft_memset(testmode, u, '$', 35);
	char v[] = "CASH rules everything around me";
	test_ft_memset(testmode, v, '$', 0);	
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