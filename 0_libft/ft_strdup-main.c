#include "libft.h"

// MORE TESTS
void	test_ft_strdup(bool testmode, char *str)
{
	char *result;
	if(testmode)
		result = strdup(str);
	else
		result = ft_strdup(str);
	printf("The string : %s\n", result);
}

void	tests_ft_strdup(bool testmode)
{
	test_ft_strdup(testmode, "Helloworld");
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_strdup(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_strdup(false);
	}
	return 0;
}