#include "libft.h"

void	test_ft_strlcpy(bool testmode, int size)
{
	char string[] = "Forty Two Thousand";
	char buffer[19];
	int r;
	if(testmode)
		r = strlcpy(buffer,string,size);
	else
		r = ft_strlcpy(buffer,string,size);
	printf("Copied '%s' into '%s', length %d\n",
		string,
		buffer,
		r
	);
}

void	tests_ft_strlcpy(bool testmode)
{
	test_ft_strlcpy(testmode, 19);
    test_ft_strlcpy(testmode, 10);
    test_ft_strlcpy(testmode, 1);
    test_ft_strlcpy(testmode, 0);	
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_strlcpy(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_strlcpy(false);
	}
	return 0;
}