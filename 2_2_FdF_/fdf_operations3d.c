#include "fdf.h"

t_matrix3d	*create_3d_matrix(char *filename)
{
	t_matrix3d		*matrix3d;
	t_point3d		*values;
	t_point3d		**points;
	int				fd;
	int				i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file!\n");
		return (NULL);
	}
	matrix3d = malloc(sizeof(t_matrix3d));
	if (matrix3d == NULL)
		return (NULL);
	if (get_dimensions(filename, matrix3d) == -1)
	{
		printf("Error retrieving matrix dimensions!\n");
		return (NULL);
	}
	values = malloc(matrix3d->nrows * matrix3d->ncols * sizeof(t_point3d));
	if (values == NULL)
		return (NULL);
	points = malloc(matrix3d->nrows * sizeof(t_point3d*));
	if (points == NULL)
		return (NULL);
	i = 0;
	while(i < matrix3d->nrows)
	{
		points[i] = values + i * matrix3d->ncols;
		i++;
	}
	matrix3d->points = points;
	read_coords_from_file(fd, matrix3d);
	return (matrix3d);
}

void	print_3d_matrix(t_matrix3d *matrix3d)
{
	int	irow;
	int	icol;

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

void rotate(float *x, float *y, float angle)
{
	float tx;
	float ty;

	tx = *x;
	ty = *y;
	*x = tx * cos(angle) - ty * sin(angle);
	*x = tx * sin(angle) + ty * cos(angle);
}

void	convert_matrix(t_matrix3d *matrix3d, t_matrix2d *matrix2d)
{
	int	irow;
	int	icol;
	float			x;
	float			y;

	irow = 0;
	icol = 0;
	while(icol < matrix3d->ncols)
	{
		while(irow < matrix3d->nrows)
		{
			// NOTE: origin is top left
			// isometric projection:
			x = (float)matrix3d->points[irow][icol].axis + cos(matrix2d->iso_angle) * (float)matrix3d->points[irow][icol].altitude - cos(matrix2d->iso_angle) * (float)(matrix3d->points[irow][icol].ordinate);
			y = -((float)matrix3d->points[irow][icol].ordinate) * sin(matrix2d->iso_angle) - (float)matrix3d->points[irow][icol].altitude * sin(matrix2d->iso_angle);
			// rotation:
			rotate(&x, &y, matrix2d->rot_angle);
			// translation:
			x += matrix2d->trans->x;
			y += matrix2d->trans->y;			
			// scaling based on zoom level:
			x = ((x + (matrix2d->nrows - 1)) / ((matrix2d->nrows - 1) * 2)) * ((matrix2d->nrows - 1) * matrix2d->zoom_level);
			y = ((y + (matrix2d->ncols - 1)) / ((matrix2d->ncols - 1) * 2)) * ((matrix2d->ncols - 1) * matrix2d->zoom_level);
			matrix2d->points[irow][icol].x = (int)round(x);
			matrix2d->points[irow][icol].y = (int)round(y);
			irow++;
		}
		irow = 0;
		icol++;
	}
}