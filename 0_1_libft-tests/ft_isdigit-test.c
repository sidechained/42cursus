#include "../0_libft/libft.h"
#include <ctype.h>
#include <stdio.h>

void	test_ft_bzero(bool testmode, int c)
{
	int isdig;
	if(testmode)
		isdig = isdigit(c);
	else
		isdig = ft_isdigit(c);
	if (isdig)
	  printf("'%c' is a digit\n", c);
	else
	  printf("'%c' is not a digit\n", c);
	printf("\n");
}

void	tests_ft_bzero(bool testmode)
{
	test_ft_bzero(testmode, 'h');
	test_ft_bzero(testmode, '2');
	test_ft_bzero(testmode, '\t');
	test_ft_bzero(testmode, '\n');
	test_ft_bzero(testmode, '\0');		
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_bzero(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_bzero(false);
	}
	return 0;
}