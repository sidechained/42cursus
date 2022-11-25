#include "../0_libft/inc/libft.h"

// FAIL

void	test_ft_itoa(int n)
{
	char *res;
	res = ft_itoa(n);
	printf("- converting integer %i\nRESULT = string \"%s\"\n\n", n, res);
}

int	main()
{
	printf("TEST: Positive integer...\n");
	test_ft_itoa(9876);
	printf("TEST: Zero...\n");	
	test_ft_itoa(0);
	printf("TEST: Negative integer...\n");	
	test_ft_itoa(-9876);
	printf("TEST: Positive integer at limit [beyond limit gives warning]...\n");	
	test_ft_itoa(2147483647);
	printf("TEST: Negative integer at limit...\n");	
	test_ft_itoa(-2147483647);
	printf("TEST: Negative integer beyond limit...\n");	
	test_ft_itoa(-2147483648);
}