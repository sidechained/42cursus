#include "../0_libft/inc/libft.h"

void	test_ft_strtrim(char const *s1, char const *set)
{
	char *res;
	res = ft_strtrim(s1, set);
	printf("- trimming \"%s\" using set \"%s\"\nRESULT = \"%s\"\n\n", s1, set, res);
}

int	main()
{
	printf("TEST: Trimming standard string by standard set...\n");
	test_ft_strtrim("abcnother funa", "abc");
	// printf("TEST: Trimming whitespace [space tab newline]...\n");
	// test_ft_strtrim("a bc n o\tth\ner f\tuna\n", " 	\n");
	// printf("TEST: Set is an empty string [string to trim should be unchanged]...\n");
	// test_ft_strtrim("abcnother funa", "");
	// printf("TEST: String to trim is empty [should also return empty]...\n");
	// test_ft_strtrim("", "abc");
	// printf("TEST: Both set and string-to-trim are empty [should also return empty]...\n");
	// test_ft_strtrim("", "");
	// printf("TEST: Both set and string-to-trim are empty [should also return empty]...\n");
	// test_ft_strtrim("", "");	
	return (0);
}