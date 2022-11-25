#include "../0_libft/inc/libft.h"
#include <ctype.h> // toupper

char test_toupper(unsigned int i, char c)
{
	(void)i;
	int r;
	r = toupper(c);
	return (r);
}

char test_isdigit(unsigned int i, char c)
{
	int r;
	r = isdigit(c);
	if (r != 1)
	{
		r = i;
	}
	return (r + '0');
}

void	test_ft_strmapi_toupper(char const *s)
{
	char *res;
	printf("- using string \"%s\"\n", s);
	res = ft_strmapi(s, test_toupper);
	printf("RESULT = \"%s\"\n\n", res);
}

void	test_ft_strmapi_isdigit(char const *s)
{
	char *res;
	printf("- using string \"%s\"\n", s);
	res = ft_strmapi(s, test_isdigit);
	printf("RESULT = \"%s\"\n\n", res);
}

int	main()
{
	printf("TEST: Applying 'toupper' function to standard string containing no spaces...\n");
	test_ft_strmapi_toupper("TestTing");
	printf("TEST: Applying 'toupper' function to string containing whitespace...\n");	
	test_ft_strmapi_toupper(" Function\tTest\tThirty-Five");
	printf("TEST: Applying 'toupper' function to empty string...\n");	
	test_ft_strmapi_toupper("");
	printf("TEST: Applying 'isdigit' function to index, returning 1 when digit found, else index (as char)...\n");	
	test_ft_strmapi_isdigit("T3st1ngT1ng");	
	printf("TEST: Applying 'isdigit' function to index, returning 1 when digit found, else index (as char)...\n");	
	test_ft_strmapi_isdigit("000--xxx--111");	
}