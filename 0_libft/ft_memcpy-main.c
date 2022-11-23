#include "libft.h"

void	test_ft_memcpy(bool testmode, void *dest, const void *src, size_t n)
{
	printf("%s\n", dest);
	if (testmode)
		memcpy(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	printf("%s\n\n", dest);
}

void	tests_ft_memcpy(bool testmode)
{
	char dest[50] = "This string should be replaced by...";
	const char src[50] = "...this amazing string!";
	test_ft_memcpy(testmode, dest, src, strlen(src)+1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_memcpy(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_memcpy(false);
	}
	return 0;
}