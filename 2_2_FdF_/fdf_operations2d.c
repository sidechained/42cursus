#include "fdf.h"

t_matrix2d	*create_2d_matrix(int nrows, int ncols)
{
	int i;

	t_matrix2d *matrix2d = malloc(sizeof(t_matrix2d));
	matrix2d->nrows = nrows;
	matrix2d->ncols = ncols;
	t_point2d* values = malloc(nrows * ncols * sizeof(t_point2d)); // enough memory for all the values
	t_point2d** points = malloc(nrows * sizeof(t_point2d*)); // these are pointers to ints (existing ones?)
	i = 0;
	while(i < nrows)
	{
	points[i] = values + i*ncols; // increment the values pointer 
	i++;
	}
	matrix2d->points = points;
	calc_zoom_level_and_window_size(matrix2d);
	return (matrix2d);
}

void	print_2d_matrix(t_matrix2d *matrix2d)
{
	unsigned int irow;
	unsigned int icol;

	irow = 0;
	icol = 0;
	while(icol < matrix2d->nrows)
	{
		while(irow < matrix2d->ncols)
		{
			printf("[%i][%i]:\n", irow, icol);
			printf(" x: %i\n", (matrix2d->points[irow] + icol)->x); 
			printf(" y: %i\n", (matrix2d->points[irow] + icol)->y);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

void	calc_zoom_level_and_window_size(t_matrix2d *matrix2d)
{
	unsigned int proposed_win_width;
	unsigned int proposed_win_height;
	float w;
	float h;

	proposed_win_width = DEFAULT_SPACING * (matrix2d->nrows - 1);
	proposed_win_height = DEFAULT_SPACING * (matrix2d->ncols - 1);
	// printf("ww: %i %i : %i %i\n", proposed_win_width, proposed_win_height, MAX_WIN_WIDTH, MAX_WIN_HEIGHT);
	if (proposed_win_width > MAX_WIN_WIDTH)
	{
		matrix2d->win_width = MAX_WIN_WIDTH;
		w = MAX_WIN_WIDTH / (matrix2d->nrows - 1);
	}
	else
	{
		matrix2d->win_width = proposed_win_width;
		w = DEFAULT_SPACING;
	}
	if (proposed_win_height > MAX_WIN_HEIGHT)
	{
		matrix2d->win_height = MAX_WIN_HEIGHT;
		h = MAX_WIN_HEIGHT / (matrix2d->ncols - 1);
	}
	else
	{
		matrix2d->win_height = proposed_win_height;
		h = DEFAULT_SPACING;
	}
	if (w < h)
		matrix2d->zoom_level = w;
	else
		matrix2d->zoom_level = h;
}
