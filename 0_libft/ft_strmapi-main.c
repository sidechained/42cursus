#include "libft.h"
#include <ctype.h> // toupper

//TODO test i, test with more than one function

char test_toupper(unsigned int i, char c)
{
	(void)i;
	int r;
	r = toupper(c);
	return (r);
}

void	test_ft_strmapi(char const *s)
{
	char *res;
	printf("before:%s", s);
	res = ft_strmapi(s, test_toupper);
	printf("after :%s", res);
}

int	main()
{
	test_ft_strmapi("TestTing\n");
	test_ft_strmapi("Function Test Thirty-Five\n");	
}