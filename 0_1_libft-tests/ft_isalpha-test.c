#include "../0_libft/libft.h"
#include <ctype.h>
#include <stdio.h>

void  test_ft_isalpha(bool testmode, int var)
{
	int isan;
	if(testmode)
		isan = isalpha(var);
	else
		isan = ft_isalpha(var);
	if(isan)
		printf("'%c' is alphabetic\n", var);
	else
		printf("'%c' is not alphabetic\n", var);
	printf("\n");
}

void  tests_ft_isalpha(bool testmode)
{
	test_ft_isalpha(testmode, 'A');
	test_ft_isalpha(testmode, 'Z');	
	test_ft_isalpha(testmode, 'd');
	test_ft_isalpha(testmode, 'z');	
	test_ft_isalpha(testmode, '2');
	test_ft_isalpha(testmode, '\t');
	test_ft_isalpha(testmode, ' ');
	test_ft_isalpha(testmode, '\0');	
}

int   main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_isalpha(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_isalpha(false);
	}
	return 0;
}