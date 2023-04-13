#include "fdf.h"

matrix_3d	*init_3d_matrix(int nrows, int ncols)
{
	int i;

	matrix_3d	*matrix3d = malloc(sizeof(matrix_3d));
    point_3d	*values = malloc(nrows*ncols*sizeof(point_3d)); // enough memory for all the values
    point_3d	**points = malloc(nrows*sizeof(point_3d*)); // these are pointers to ints (existing ones?)
    i = 0;
    while(i < nrows)
    {
        points[i] = values + i*ncols; // increment the values pointer 
    	i++;
    }
    matrix3d->points = points;
    return (matrix3d);
}

matrix_2d	*init_2d_matrix(int nrows, int ncols)
{
	int i;

	matrix_2d *matrix2d = malloc(sizeof(matrix_2d));
    point_2d* values = malloc(nrows*ncols*sizeof(point_2d)); // enough memory for all the values
    point_2d** points = malloc(nrows*sizeof(point_2d*)); // these are pointers to ints (existing ones?)
    i = 0;
    while(i < nrows)
    {
        points[i] = values + i*ncols; // increment the values pointer 
    	i++;
    }
    matrix2d->points = points;
    return (matrix2d);
}