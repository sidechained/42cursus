#include "fdf.h"

t_matrix3d	*create_3d_matrix(char *filename)
{
	t_matrix3d		*matrix3d;
	unsigned int	i;
	t_point3d		*values;
	t_point3d		**points;
	int				ret;

	matrix3d = malloc(sizeof(t_matrix3d));
	ret = get_dimensions(filename, matrix3d); // HANDLE NULL!
	if (ret == -1)
	{
		free(matrix3d);
		return (NULL);
	}
	values = malloc(matrix3d->nrows * matrix3d->ncols * sizeof(t_point3d));
	points = malloc(matrix3d->nrows * sizeof(t_point3d*));

	i = 0;
	while(i < matrix3d->nrows)
	{
		points[i] = values + i * matrix3d->ncols; // increment the values pointer 
		i++;
	}
	matrix3d->points = points;
	read_coords_from_file(filename, matrix3d);

	return (matrix3d);
}

void	print_3d_matrix(t_matrix3d *matrix3d)
{
	unsigned int	irow;
	unsigned int	icol;

	irow = 0;
	icol = 0;
	while(icol < matrix3d->nrows)
	{
		while(irow < matrix3d->ncols)
		{
			printf("[%i][%i]:\n", irow, icol);
			printf(" axis: %i\n", (matrix3d->points[irow] + icol)->axis);   
			printf(" ord : %i\n", (matrix3d->points[irow] + icol)->ordinate);
			printf(" alt : %i\n", (matrix3d->points[irow] + icol)->altitude);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

void	convert_matrix(t_matrix3d *matrix3d, t_matrix2d *matrix2d)
{
	unsigned int	irow;
	unsigned int	icol;
	float			x;
	float			y;

	irow = 0;
	icol = 0;
	while(icol < matrix3d->ncols)
	{
		while(irow < matrix3d->nrows)
		{
			// origin is top left
			// calc x projection based on axis, alt, ord
			x = (float)matrix3d->points[irow][icol].axis + cos(matrix2d->iso_angle) * (float)matrix3d->points[irow][icol].altitude - cos(matrix2d->iso_angle) * (float)(matrix3d->points[irow][icol].ordinate);
			// printf("x:%f	", x);
			x = ((x + (matrix2d->nrows - 1)) / ((matrix2d->nrows - 1) * 2)) * matrix2d->win_width;
			y = -((float)matrix3d->points[irow][icol].ordinate) * sin(matrix2d->iso_angle) - (float)matrix3d->points[irow][icol].altitude * sin(matrix2d->iso_angle);
			// printf("y:%f\n", y);
			y = ((y + (matrix2d->ncols - 1)) / ((matrix2d->ncols - 1) * 2)) * matrix2d->win_height;
			matrix2d->points[irow][icol].x = (int)round(x); // is round allowed?
			matrix2d->points[irow][icol].y = (int)round(y); // is round allowed?
			irow++;
		}
		irow = 0;
		icol++;
	}
}