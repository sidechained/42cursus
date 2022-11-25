#include "../0_libft/inc/libft.h"
#include <ctype.h>

void	test_ft_isprint(bool testmode, int var)
{
	int ispr;
	if(testmode)
		ispr = isprint(var);
	else
		ispr = ft_isprint(var);
	if(ispr)
		printf("'%c' can be printed\n", var);
	else
		printf("'%c' can't be printed\n", var);
	printf("\n");
}

void	tests_ft_isprint(int testmode)
{
	test_ft_isprint(testmode, 'k');
	test_ft_isprint(testmode, '8');
	test_ft_isprint(testmode, '\t');
	test_ft_isprint(testmode, ' ');
	test_ft_isprint(testmode, '\0');	
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_isprint(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_isprint(false);
	}
	return 0;
}