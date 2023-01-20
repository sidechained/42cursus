#include "../0_libft/libft.h"
#include <stdio.h>

#define STR_SIZE 50

void	test_ft_memcpy(bool testmode, char *dest, const void *src, size_t n)
{
	printf("BEFORE:\"");
	int i = 0;
	while(i < STR_SIZE)
	{
		printf("%c", dest[i]);
		i++;
	}
	printf("\"\n");	
	if (testmode)
		memcpy(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	i = 0;
	printf("AFTER: \"");
	while(i < STR_SIZE)
	{
		printf("%c", dest[i]);
		i++;
	}
	printf("\"\n\n");	
}

void	tests_ft_memcpy(bool testmode)
{
	char dest[STR_SIZE] = 		"Please replace part of me";
	const char src[STR_SIZE] =  "The new better";
	test_ft_memcpy(testmode, dest, src, strlen(src));
	char dest2[STR_SIZE] = 		"IMPROVEDIMPROVEDIMPROVED";
	const char src2[STR_SIZE] =  "BETTERBETTERBETTER";
	test_ft_memcpy(testmode, dest2, src2, strlen(src2));
	char dest3[STR_SIZE] = 		"ONE\0 TWO\0 THREE\0";
	const char src3[STR_SIZE] =  "HUP\0 BETTERBETTER";
	test_ft_memcpy(testmode, dest3, src3, strlen(src3));
	char dest4[STR_SIZE] = 		"I\tTAB\nNEWLINE SPACE";
	const char src4[STR_SIZE] =  "U SPACE\nNEWLINE\tTAB";
	test_ft_memcpy(testmode, dest4, src4, strlen(src4));
	char dest5[STR_SIZE] = 		"IMPROVED";
	const char src5[STR_SIZE] =  "BETTERBETTERBETTER";
	test_ft_memcpy(testmode, dest5, src5, strlen(src5));		
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_memcpy(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_memcpy(false);
	}
	return 0;
}