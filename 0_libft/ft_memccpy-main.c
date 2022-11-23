#include "libft.h"

void	test_ft_memccpy(bool testmode)
{
	(void)testmode;
	char bigString[1000];
	char* end = bigString + sizeof bigString;
	char* p = memccpy(bigString, "Example of repeatedly ", 0, sizeof bigString);
	puts(bigString);
	if (p) p = memccpy(p - 1, "using memccpy copy ", 0, end - p);
	puts(bigString);
	if (p) p = memccpy(p - 1, "to ", 0, end - p);
	puts(bigString);
	if (p) p = memccpy(p - 1, "append ", 0, end - p); 
	puts(bigString);
}

void	tests_ft_memccpy(bool testmode)
{
	test_ft_memccpy(testmode);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_memccpy(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_memccpy(false);
	}
	return 0;
}