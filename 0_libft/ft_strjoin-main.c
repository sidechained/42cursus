#include "libft.h"

// FAILS

void	test_ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	res = ft_strjoin(s1, s2);
	printf("Joining \"%s\" with \"%s\". Result = \"%s\"\n", s1, s2, res);
}

int	main()
{
	test_ft_strjoin("Testing", "Ting");
	test_ft_strjoin("", "");
	test_ft_strjoin(NULL, NULL);
	return (0);
}