#include "fdf.h"

// ideally, window width and height are determined by adding up the spacing between points (DEFAULT_SPACING)
// however there may be so many points that the proposed_win_width/height exceeds MAX_WIN_WIDTH/HEIGHT
// in this case we reduce the DEFAULT_SPACING so that all points fit on screen
float	calc_zoom_level_and_window_size(matrix_2d *matrix2d, int nrows, int ncols)
{
	unsigned int proposed_win_width;
	unsigned int proposed_win_height;
	float w;
	float h;

	proposed_win_width = DEFAULT_SPACING * (nrows - 1) + 1;
	proposed_win_height = DEFAULT_SPACING * (ncols - 1) + 1;

	printf("pww %u, pwh %u\n", proposed_win_width, proposed_win_height);

	if (proposed_win_width > MAX_WIN_WIDTH)
	{
		matrix2d->win_width = MAX_WIN_WIDTH;
		w = MAX_WIN_WIDTH / nrows;
	}
	else
	{
		matrix2d->win_width = proposed_win_width;
		w = DEFAULT_SPACING;
	}

	if (proposed_win_height > MAX_WIN_HEIGHT)
	{
		matrix2d->win_height = MAX_WIN_HEIGHT;
		h = MAX_WIN_HEIGHT / ncols;
	}
	else
	{
		matrix2d->win_height = proposed_win_height;
		h = DEFAULT_SPACING;
	}
	printf("ww %u, wh %u\n", matrix2d->win_width, matrix2d->win_height);
	if (w < h)
	{
		printf("zoom: %f\n", w);
		return(w);
	}
	printf("zoom: %f\n", h);
	return(h);
}

// use basic trigonometry to calculate x and y from axis, ordinate and altitude
// NOTE: ideally we would take a pointer to matrix 3d, to avoid copying and extra memory usage
matrix_2d	*matrix_3d_to_2d_iso(matrix_3d *matrix3d, matrix_2d *matrix2d, int nrows, int ncols, float angle)
{
	int irow;
	int icol;

	irow = 0;
	icol = 0;
	while(icol < ncols)
	{
		while(irow < nrows)
		{
			matrix2d->points[irow][icol].x = matrix3d->points[irow][icol].axis + cos(angle) * matrix3d->points[irow][icol].altitude - cos(angle) * matrix3d->points[irow][icol].ordinate;
			matrix2d->points[irow][icol].y = -(matrix3d->points[irow][icol].ordinate) * sin(angle) - matrix3d->points[irow][icol].altitude * sin(angle);	
			irow++;
		}
		irow = 0;
		icol++;
	}
	return(matrix2d);
}

// use basic trigonometry to calculate x and y from axis, ordinate and altitude
// NOTE: ideally we would take a pointer to matrix 3d, to avoid copying and extra memory usage
matrix_2d	*matrix_3d_to_2d_flat(matrix_3d	*matrix3d, matrix_2d *matrix2d, int nrows, int ncols)
{
	int irow;
	int icol;
	// float zoom_level;

	irow = 0;
	icol = 0;
	// zoom_level = calc_zoom_level_and_window_size(matrix2d, nrows, ncols);
	while(icol < ncols)
	{
		while(irow < nrows)
		{
			matrix2d->points[irow][icol].x = matrix3d->points[irow][icol].axis;
			matrix2d->points[irow][icol].y = matrix3d->points[irow][icol].ordinate;

			// matrix2d->points[irow][icol].x = matrix3d->points[irow][icol].axis * zoom_level;
			// matrix2d->points[irow][icol].y = matrix3d->points[irow][icol].ordinate * zoom_level;
			irow++;
		}
		irow = 0;
		icol++;
	}
	return(matrix2d);
}


// WHAT SHOULD THIS FUNCTION ACTUALLY BE DOING?!
// scale the produced 2d matrix by window width and height
// NOTE: ideally we would take a pointer to matrix 3d, to avoid copying and extra memory usage
matrix_2d	*scale_2d_matrix(matrix_2d *matrix2d, int nrows, int ncols)
{
	int irow;
	int icol;
	int scale;

	if (nrows > ncols)
		scale = nrows;
	else
		scale = ncols;

	irow = 0;
	icol = 0;
	while(icol < ncols)
	{
		while(irow < nrows)
		{
			// goes from -scale to scale, should go from 0 to WINDOW_WIDTH or WINDOW_HEIGHT
			matrix2d->points[irow][icol].x += scale;
			matrix2d->points[irow][icol].x /= scale * 2;		
			matrix2d->points[irow][icol].x *= matrix2d->win_width;
			matrix2d->points[irow][icol].y += scale;
			matrix2d->points[irow][icol].y /= scale * 2;		
			matrix2d->points[irow][icol].y *= matrix2d->win_height;
			irow++;
		}
		irow = 0;
		icol++;
	}
	return(matrix2d);
}
