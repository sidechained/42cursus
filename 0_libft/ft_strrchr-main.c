#include "libft.h"

void	test_ft_strrchr(bool testmode, char ch)
{
	const char str[] = "http://www.42berlin.de";
	char *ret;
	if (testmode)
		ret = strrchr(str, ch);
	else
		ret = ft_strrchr(str, ch);
	printf("Last occurance of '%c' in \"%s\" is located at \"%s\"\n", ch, str, ret);
}

void	tests_ft_strrchr(bool testmode)
{
	test_ft_strrchr(testmode, '.');
	test_ft_strrchr(testmode, 'h');
	test_ft_strrchr(testmode, 'e');
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_strrchr(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_strrchr(false);
	}
	return 0;
}