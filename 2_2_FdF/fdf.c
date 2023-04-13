#include "fdf.h"

// should nrows/ncols be integrated into 3d and 2d matrix structs?
int		main(int argc, char **argv)
{
	int			nrows;
	int			ncols;
	matrix_3d	*matrix3d;
	matrix_2d	*matrix2d;
	char 		*filename;

	int win_width;
	int win_height;

	argc--;
	argv++;
	if (argc < 1)
	{
		printf("%s", "You must supply a filename!\n");
		return (0);
	}
	filename = argv[0];
	get_3d_matrix_dimensions(filename, &nrows, &ncols); // HANDLE NULL!
	matrix3d = init_3d_matrix(nrows, ncols);
	matrix3d = read_coords_from_file(filename, matrix3d); // HANDLE NULL!
	print_3d_matrix(matrix3d, nrows, ncols);
	matrix2d = init_2d_matrix(nrows, ncols);
	matrix2d = matrix_3d_to_2d_flat(matrix3d, matrix2d, nrows, ncols);
	printf("%i %i\n", matrix2d->win_width, matrix2d->win_height);
	print_2d_matrix(matrix2d, nrows, ncols);

	// matrix2d = matrix_3d_to_2d_iso(matrix3d, matrix2d, nrows, ncols, 0.7853981634);
	// matrix2d = scale_2d_matrix(matrix2d, nrows, ncols);
	// print_2d_matrix(matrix2d, nrows, ncols);
	// plot_to_window(matrix2d, nrows, ncols);
	return (0);
}
