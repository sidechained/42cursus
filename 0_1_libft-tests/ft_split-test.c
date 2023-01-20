#include "../0_libft/libft.h"
#include <stdio.h>

void	test_ft_split(char const *s, char c)
{
	char **splits;
	int i;
	printf("- splitting \"%s\" using '%c':\nRESULTS =\n", s, c);
	splits = ft_split(s, c);
	i = 0;
	while(splits[i])
	{
		printf("split %i:\"%s\"\n", i, splits[i]);
		i++;
	}
	printf("\n");
}

int	main()
{
	printf("TEST: Splitting by space in middle of string\n");	
	test_ft_split("Test Ting", ' ');
	printf("TEST: Splitting by normal character in middle and end of string\n");	
	test_ft_split("olinkyomatic", 'o');	
	printf("TEST: Splitting by normal character in middle and end of string\n");	
	test_ft_split("Fourty Two", 'o');
	printf("TEST: Splitting by normal character at start and middle of string\n");	
	test_ft_split("oLordNotMoreTests", 'o');
	printf("TEST: Splitting by nonalpha character in a bunch of other strange characters\n");	
	test_ft_split("^ _^_ >^< ^", '^');
	printf("TEST: Splitting by tab at start middle end\n");	
	test_ft_split("	Fourty	Two	", '\t');	
	printf("TEST: Splitting by terminator '\\0' as first char (should be treated as string end?)\n");	
	test_ft_split("\0aa\0bbb", '\0');
	printf("TEST: Splitting by terminator '\\0' following a few chars (should be treated as string end?)\n");	
	test_ft_split("zz\0aa\0bbb", '\0');

	return (0);
}