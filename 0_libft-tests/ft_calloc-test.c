#include "../0_libft/inc/libft.h"

void	test_ft_calloc(bool testmode, int n)
{
	int i;
	int *a;

	printf("Allocating block of memory containing %i elements of size 'int':\n", n);
	if(testmode)
		a = (int*)calloc(n, sizeof(int));
	else
		a = (int*)ft_calloc(n, sizeof(int));
	printf("Zero check       : ");
	for( i=0 ; i < n ; i++ ) {
		printf("%d",a[i]);
	}
	printf("\n");
	for( i=0 ; i < n ; i++ ) {
		a[i] = i % 10;
	}
	printf("Allocation check : ");
	for( i=0 ; i < n ; i++ ) {
		printf("%d",a[i]);
	}
	printf("\n\n");
	free( a );
}

void tests_ft_calloc(bool testmode)
{
	test_ft_calloc(testmode, 5);
	test_ft_calloc(testmode, 50);
	test_ft_calloc(testmode, 0);
	test_ft_calloc(testmode, -5);	
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_calloc(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_calloc(false);
	}
	return 0;
}