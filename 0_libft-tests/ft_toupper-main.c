#include "libft.h"
#include <ctype.h>

void	test_ft_toupper(bool testmode, char* str)
{
	int i;
	i = 0;
	printf("\"%s\" -> \"", str);
	while(str[i]) {
		if(testmode)
			putchar(toupper(str[i]));
		else
			putchar(ft_toupper(str[i]));
		i++;
	}
	printf("\"\n");
}

void	tests_ft_toupper(bool testmode)
{
	test_ft_toupper(testmode, "forty-two berlin");
	test_ft_toupper(testmode, "FORTY-TWO BERLIN");	
	test_ft_toupper(testmode, " __42 Berlin__ ");
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_toupper(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_toupper(false);
	}
	return 0;
}