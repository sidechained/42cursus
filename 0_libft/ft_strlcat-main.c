#include "libft.h"
// NOT TOTALLY HAPPY WITH THIS

void	test_ft_strlcat(bool testmode, int size)
{
	char first[] = "This is ";
	char last[] = "a potentially long string";
	int r;
	char buffer[size];
	strcpy(buffer,first);
	printf("Concatenating \"%s\" with \"%s\" with size of %i\n",first, last, size);
	printf("BEFORE:%s\n",first);
	if(testmode)
		r = strlcat(buffer,last,size);
	else
		r = ft_strlcat(buffer,last,size);
	printf("AFTER: %s\n",buffer);
	printf("Value returned: %d\n",r);
	if (r > size)
		printf("RESULT: String was truncated\n");
	else
		printf("RESULT: String was fully copied\n");
	printf("\n");
}

void	tests_ft_strlcat(bool testmode)
{
	test_ft_strlcat(testmode, 4);
	test_ft_strlcat(testmode, 15);
	test_ft_strlcat(testmode, 50);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_strlcat(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_strlcat(false);
	}
	return 0;
}