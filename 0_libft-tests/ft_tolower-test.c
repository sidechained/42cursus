#include "../0_libft/inc/libft.h"
#include <ctype.h>

void	test_ft_tolower(bool testmode, char *str)
{
	int i;
	i = 0;
	printf("BEFORE:\"%s\"\nAFTER: \"", str);	
	while( str[i] )
	{
		if (testmode)
			putchar(tolower(str[i]));
		else
			putchar(ft_tolower(str[i]));
		i++;
	}
	printf("\"\n\n");
}

void	tests_ft_tolower(bool testmode)
{
	test_ft_tolower(testmode, "FOURTY-TWO BERLIN");
	test_ft_tolower(testmode, "Fourty-Two Berlin");
	test_ft_tolower(testmode, "42 berlin");	
	test_ft_tolower(testmode, " __42-bErLiN__ ");
	test_ft_tolower(testmode, " __ __ ");		
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_tolower(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_tolower(false);
	}
	return 0;
}