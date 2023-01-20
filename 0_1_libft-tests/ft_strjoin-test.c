#include "../0_libft/libft.h"
#include <stdio.h>

void	test_ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	res = ft_strjoin(s1, s2);
	printf("- joining \"%s\" with \"%s\".\nRESULT = \"%s\"\n\n", s1, s2, res);
}

int	main()
{
	printf("TEST: Joining two standard strings...\n");
	test_ft_strjoin("Testing", "Ting");
	printf("TEST: Joining two empty strings...\n");
	test_ft_strjoin("", "");
	printf("TEST: Joining an empty string with a standard string...\n");
	test_ft_strjoin("", "Ting");
	printf("TEST: Joining a standard string with an empty string...\n");
	test_ft_strjoin("Testing", "");
	printf("TEST: Passing NULL to both arguments...\n");
	test_ft_strjoin(NULL, NULL);
	return (0);
}