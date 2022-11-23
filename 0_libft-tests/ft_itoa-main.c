#include "libft.h"

// FAIL

void	test_ft_itoa(int n)
{
	char *res;
	res = ft_itoa(9876);
	printf("Converting integer %i. RESULT = string \"%s\"\n", n, res);
}

int	main()
{
	test_ft_itoa(9876);
	test_ft_itoa(-9876);
}