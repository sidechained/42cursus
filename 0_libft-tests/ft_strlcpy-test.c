#include "../0_libft/inc/libft.h"

void	test_ft_strlcpy(bool testmode, char *string, int size)
{
	char buffer[19];
	int r;
	if(testmode)
		r = strlcpy(buffer,string,size);
	else
		r = ft_strlcpy(buffer,string,size);
	printf("Copied %i chars of string '%s' into buffer '%s'\nReturned total length = %d\n\n",
		size,
		string,
		buffer,
		r
	);
}

void	tests_ft_strlcpy(bool testmode)
{
	test_ft_strlcpy(testmode, "Forty Two Thousand", 19);
    test_ft_strlcpy(testmode, "Forty Two Thousand", 10);
    test_ft_strlcpy(testmode, "Forty Two Thousand", 1);
    test_ft_strlcpy(testmode, "Forty Two Thousand", 0);	
    test_ft_strlcpy(testmode, "", 5);    
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