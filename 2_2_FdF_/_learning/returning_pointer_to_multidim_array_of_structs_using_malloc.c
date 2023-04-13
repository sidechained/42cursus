// mallocing approach

#include <stdio.h>
#include <stdlib.h> // remove and use ft_funcs

typedef struct point3d
{
	unsigned int axis;
	unsigned int ordinate;
	int altitude;
} point3d;

point3d** create_3d_matrix(int nrows, int ncols)
{
    point3d* values = malloc(nrows*ncols*sizeof(point3d)); // enough memory for all the values
    point3d** rows = malloc(nrows*sizeof(point3d*)); // these are pointers to ints (existing ones?)
    for (int i=0; i<nrows; ++i)
    {
        rows[i] = values + i*ncols; // increment the values pointer 
    }
    return rows;
}

void destroy_3d_matrix(point3d** matrix3d)
{
    free(*matrix3d);
    free(matrix3d);
}

void print_3d_matrix(point3d** coords, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < nrows)
	{
		while(irow < ncols)
		{
			printf("[%i][%i]:\n", irow, icol);
			printf(" axis: %i\n", (coords[irow] + icol)->axis);	
			printf(" ord : %i\n", (coords[irow] + icol)->ordinate);
			printf(" alt : %i\n", (coords[irow] + icol)->altitude);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

int main(void)
{
    point3d** matrix3d = create_3d_matrix(2,2);
    matrix3d[0][0].axis = 1;
    matrix3d[0][0].ordinate = 10;
    matrix3d[0][0].altitude = 100;        
    matrix3d[0][1].axis = 2;
    matrix3d[0][1].ordinate = 20;
    matrix3d[0][1].altitude = 200;
    matrix3d[1][0].axis = 3;   
    matrix3d[1][0].ordinate = 30;
    matrix3d[1][0].altitude = 300;   
    matrix3d[1][1].axis = 4;
    matrix3d[1][1].ordinate = 40;
    matrix3d[1][1].altitude = 400;      
    print_3d_matrix(matrix3d, 2, 2); 
    destroy_3d_matrix(matrix3d);
}