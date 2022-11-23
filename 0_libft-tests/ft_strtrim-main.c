#include "libft.h"

// FAILS

void	test_ft_strtrim(char const *s1, char const *set)
{
	char *res;
	res = ft_strtrim(s1, set);
	printf("Trim \"%s\" using set \"%s\". RESULT = \"%s\"\n", s1, set, res);
}

int	main()
{
	test_ft_strtrim("abcnother funa", "abc");
	return (0);
}