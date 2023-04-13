// when it comes to multidimensional arrays, we cannot seem to use same approach of returning a pointer
// simply: we have to malloc or calloc it, to be able to return it as a pointer to a mulitdimensional array

// https://stackoverflow.com/questions/5201708/how-to-return-a-2d-array-from-a-function-in-c

#include <stdio.h>

typedef struct point3d
{
	unsigned int axis;
	unsigned int ordinate;
	int altitude;
} point3d;

point3d *print_me(point3d matrix[1][1])
{
	int irow;
	int icol;

	irow = 0;
	icol = 0;
	while(icol <= 1)
	{
		while(irow <= 1)
		{
			printf("%i\n", matrix[irow][icol].axis);
			irow++;
		}
		irow = 0;
		icol++;
	}
	return (matrix);
}

int		main()
{
	point3d matrix[1][1];
	point3d *ret_matrix;

	matrix[0][0].axis = 10;
	matrix[0][1].axis = 20;
	matrix[1][0].axis = 30;		
	matrix[1][1].axis = 40;

	ret_matrix = print_me(matrix);
	printf("\n");
	printf("%i\n", ret_matrix[0][0].axis);
	printf("%i\n", ret_matrix[0][1].axis);
	printf("%i\n", ret_matrix[1][0].axis);
	printf("%i\n", ret_matrix[1][1].axis);	
}