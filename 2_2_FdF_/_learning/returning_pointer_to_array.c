// Q: how to return an array? A: we cannot, but we can return a pointer to the array (array name without index)
// but then how can it be indexed? we add to the pointer address before deferencing to print

printf("%i\n", *(array));

#include <stdio.h>

int *print_me(int array[3])
{
	int i;

	i = 0;
	while(i < 3)
	{
		printf("%i\n", array[i]);
		i++;
	}
	return (array);
}

int		main()
{
	int array[3];
	int *ret_array;

	array[0] = 10;
	array[1] = 20;
	array[2] = 30;		

	ret_array = print_me(array);
	printf("\n");
	printf("%i\n", *(array));
	printf("%i\n", *(array + 1));
	printf("%i\n", *(array + 2));
}

