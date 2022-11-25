#include "../0_libft/inc/libft.h"

void	test_ft_strnstr(bool testmode, char *largestring, char *smallstring, int size)
{
	char truncated_largestring[size];
	strlcpy(truncated_largestring, largestring, size+1);
	char *ptr;
	printf("Trying to find \"%s\" in %i characters of \"%s\" [\"%s\"]\n", smallstring, size, largestring, truncated_largestring);
	if (testmode)
		ptr = strnstr(largestring, smallstring, size);
	else
		ptr = ft_strnstr(largestring, smallstring, size);
	printf("RESULT: \"%s\"\n\n", ptr);
}

void	tests_ft_strnstr(bool testmode)
{
	test_ft_strnstr(testmode, "Foo Bar Baz", "Bar", 11);
	test_ft_strnstr(testmode, "Foo Bar Baz", "Bar", 4);
	test_ft_strnstr(testmode, "Baz", "Foo Bar Baz", 11);
	test_ft_strnstr(testmode, "Baz", "Foo Bar Baz", 4);
	test_ft_strnstr(testmode, "Can I BeFound", "NotFound", 11);
	test_ft_strnstr(testmode, "Fo long and fanks for fall the fish", "f", 4);	
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_strnstr(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_strnstr(false);
	}
	return 0;
}