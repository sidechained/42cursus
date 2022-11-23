#include "libft.h"
#include <ctype.h>

void  test_ft_isascii(bool testmode, int ch)
{
	int isasc;
	printf("%#04x    ", ch);
	if(testmode)
		isasc = isascii(ch);
	else
		isasc = ft_isascii(ch);
	if (isasc)
		printf("The character is %c\n", ch);
	else
		printf("Cannot be represented by an ASCII character\n");
}

void  tests_ft_isascii(int testmode)
{
	int ch;
	for (ch = 0x7c; ch <= 0x82; ch++)
		test_ft_isascii(testmode, ch);
}

int   main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_isascii(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_isascii(false);
	}
	return 0;
}