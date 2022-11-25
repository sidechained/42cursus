// array must be terminated with NULL
// each string in array must be terminated with '\0'
// therefore:
// s "Test Ting" with c ' ' will result into an array of size 3: "Test", "Ting", NULL

// Q: should splits on start and end result in ""?

#include "../0_libft/inc/libft.h"

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
	test_ft_split("Fourty Two", 'o');
	printf("TEST: Splitting by normal character at start and middle of string\n");	
	test_ft_split("oLordNotMoreTests", 'o');
	printf("TEST: Splitting by nonalpha character in a bunch of other strange characters\n");	
	test_ft_split("^ _^_ >^< ^", '^');
	printf("TEST: Splitting by tab at start middle end\n");	
	test_ft_split("	Fourty	Two	", '\t');	
	return (0);
}