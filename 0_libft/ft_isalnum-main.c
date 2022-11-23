#include "libft.h"
#include <ctype.h>

void  test_ft_isalnum(bool testmode, int var)
{
	int isan;
	if(testmode)
		isan = isalnum(var);
	else
		isan = ft_isalnum(var);
	if(isan)
		printf("'%c' is alphanumeric\n", var);
	else
		printf("'%c' is not alphanumeric\n", var);
}

void  tests_ft_isalnum(bool testmode)
{
	test_ft_isalnum(testmode, 'd');
	test_ft_isalnum(testmode, '2');
	test_ft_isalnum(testmode, '\t');
	test_ft_isalnum(testmode, ' ');
}

int   main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_isalnum(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_isalnum(false);
	}
	return 0;
}