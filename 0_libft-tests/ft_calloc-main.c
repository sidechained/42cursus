#include "libft.h"

// MORE TESTS!

void	test_ft_calloc(bool testmode)
{
	int i, n;
	int *a;

	n = 5;
	if(testmode)
		a = (int*)calloc(n, sizeof(int));
	else
		a = (int*)ft_calloc(n, sizeof(int));
	for( i=0 ; i < n ; i++ ) {
		a[i] = i;
	}
	for( i=0 ; i < n ; i++ ) {
		printf("%d ",a[i]);
	}
	printf("\n");
	free( a );
}

void tests_ft_calloc(bool testmode)
{
	test_ft_calloc(testmode);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		test_ft_calloc(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		test_ft_calloc(false);
	}
	return 0;
}