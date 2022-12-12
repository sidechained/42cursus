#include "../0_libft/libft.h"
#include <stdio.h>

void	test_tolower(unsigned int i, char *c)
{
	(void)i;
	*c -= 32;
}

void	test_toupper(unsigned int i, char *c)
{
	(void)i;
	*c += 32;
}

void	test_increment_by_index(unsigned int i, char *c)
{
	*c + i;
}

void	test_ft_striteri_tolower(char *s)
{
	printf("- using string \"%s\"\n", s);
	ft_striteri(s, test_tolower);
	printf("RESULT = \"%s\"\n\n", s);
}

void	test_ft_striteri_toupper(char *s)
{
	printf("- using string \"%s\"\n", s);
	ft_striteri(s, test_toupper);
	printf("RESULT = \"%s\"\n\n", s);
}

void	test_ft_striteri_increment_by_index(char *s)
{
	printf("- using string \"%s\"\n", s);
	ft_striteri(s, test_increment_by_index);
	printf("RESULT = \"%s\"\n\n", s);
}

int	main()
{
	printf("TEST: Applying 'tolower' function to string containing no spaces...\n");
	char *s = "TESTING";
	test_ft_striteri_tolower(s);
	printf("TEST: Applying 'toupper' function to string containing no spaces...\n");
	char *s2 = "testing";
	test_ft_striteri_toupper(s2);
	printf("TEST: Applying 'increment_by_index' function to string containing no spaces...\n");
	char *s3 = "aaaaaaa";
	test_ft_striteri_increment_by_index(s3);		
}