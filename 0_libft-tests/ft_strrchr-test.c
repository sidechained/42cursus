#include "../0_libft/inc/libft.h"

void	test_ft_strrchr(bool testmode, char *str, char ch)
{
	char *ret;
	if (testmode)
		ret = strrchr(str, ch);
	else
		ret = ft_strrchr(str, ch);
	printf("Last occurance of '%c' in \"%s\" is located at \"%s\"\n\n", ch, str, ret);
}

void	tests_ft_strrchr(bool testmode)
{
	test_ft_strrchr(testmode, "http://www.42berlin.de", '.');
	test_ft_strrchr(testmode, "http://www.42berlin.de", 'h');
	test_ft_strrchr(testmode, "http://www.42berlin.de", 'e');
	test_ft_strrchr(testmode, "http://www.42berlin.de", ' ');
	test_ft_strrchr(testmode, "	my cat is a	tabby", '\t');
	test_ft_strrchr(testmode, " spaceAtBeginning", ' ');
	test_ft_strrchr(testmode, "space at end ", ' ');	
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