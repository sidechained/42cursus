#include "../0_libft/inc/libft.h"
// NOT TOTALLY HAPPY WITH THIS

void	test_ft_strlcat(bool testmode, char *first, char *last, int size)
{
	int r;
	char buffer[size];
	strcpy(buffer,first);
	printf("Concatenating \"%s\" with \"%s\" with size of %i\n",first, last, size);
	printf("BEFORE:\"%s\"\n",first);
	if(testmode)
		r = strlcat(buffer,last,size);
	else
		r = ft_strlcat(buffer,last,size);
	printf("AFTER: \"%s\"\n",buffer);	
	if (r > size)
		printf("RESULT: String was truncated. ");
	else
		printf("RESULT: String was fully copied. ");
	printf("Value returned: %d\n\n",r);
}

void	tests_ft_strlcat(bool testmode)
{
	test_ft_strlcat(testmode, "This is ", "a potentially long string", 50);
	test_ft_strlcat(testmode, "This is ", "a potentially long string", 4);
	test_ft_strlcat(testmode, "This is ", "a potentially long string", 15);
	test_ft_strlcat(testmode, "Second string is...", "much longer than the first", 50);
	test_ft_strlcat(testmode, "Second string is...", "much longer than the first", 2);
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