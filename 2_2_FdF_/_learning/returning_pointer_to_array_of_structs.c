#include <stdio.h>

typedef struct point3d
{
	unsigned int axis;
	unsigned int ordinate;
	int altitude;
} point3d;

point3d *print_me(point3d matrix[3])
{
	int i;

	i = 0;
	while(i < 3)
	{
		printf("%i\n", matrix[i].axis);
		i++;
	}
	return (matrix);
}

int		main()
{
	point3d matrix[3];
	point3d *ret_matrix;

	matrix[0].axis = 10;
	matrix[1].axis = 20;
	matrix[2].axis = 30;		

	ret_matrix = print_me(matrix);
	printf("\n");
	printf("%i\n", ret_matrix[0].axis);
	printf("%i\n", ret_matrix[1].axis);
	printf("%i\n", ret_matrix[2].axis);		
}