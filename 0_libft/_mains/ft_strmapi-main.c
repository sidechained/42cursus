#include <stdio.h>

char test_toupper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int	main()
{
	char *str_before;
	char *str_after;

	str_before = "TestTing\n";
	printf("before:%s", str_before);
	str_after = ft_strmapi("TestTing\n", test_toupper);
	printf("after :%s", str_after);
}