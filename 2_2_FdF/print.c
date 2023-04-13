#include "fdf.h"

void	print_3d_matrix(matrix_3d *matrix3d, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < nrows)
	{
		while(irow < ncols)
		{
			printf("[%i][%i] ", irow, icol);
			printf("axis: %i, ", (matrix3d->points[irow] + icol)->axis);	
			printf("ord: %i, ", (matrix3d->points[irow] + icol)->ordinate);
			printf("alt: %i\n", (matrix3d->points[irow] + icol)->altitude);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

void	print_2d_matrix(matrix_2d *matrix2d, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < nrows)
	{
		while(irow < ncols)
		{
			printf("[%i][%i] ", irow, icol);
			printf("x: %f, 	", (matrix2d->points[irow] + icol)->x);	
			printf("y: %f\n", (matrix2d->points[irow] + icol)->y);
			irow++;
		}
		irow = 0;
		icol++;
	}
}


