#include <stdio.h>
#include <math.h>
#include <fcntl.h> // open
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

// cc -Wall -Werror -Wextra -ggdb3 matrix_from_file.c get_next_line/get_next_line.c libft/ft_strlen.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_isdigit.c && ./a.out

typedef struct point3d
{
	unsigned int axis;
	unsigned int ordinate;
	int altitude;
} point3d;

// 
int	get_coordinate_dimensions(unsigned int *num_rows, unsigned int *num_cols)
{
	char		*next_line;
	int			fd;
	char 		**split_line;
	unsigned int	prev_num_rows;	

	fd = open("test.fdf", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (0);
	}
	*num_cols = 0;
	while (1)
	{
		next_line = get_next_line(fd);
		if(next_line == NULL)
			break;
		split_line = ft_split(next_line, ' ');
		*num_rows = 0;
		while(split_line[*num_rows])
			(*num_rows)++;
		if (*num_cols > 0 && *num_rows != prev_num_rows)
			return (-1);
		prev_num_rows = *num_rows;
		free(next_line);
		(*num_cols)++;
	}	
	return (0);
}

// how to print with out providing dimensions? maybe pass as pointer, have to hardcode dimensions for now
void	print_matrix(unsigned int num_rows, unsigned int num_cols, point3d matrix[num_rows][num_cols])
{
	unsigned int irow = 0;
	unsigned int icol = 0;
	point3d point_to_print;

	while(icol < num_cols)
	{
		while(irow < num_rows)
		{
			point_to_print = matrix[irow][icol];
			printf("[%u] [%u] %u %u %i\n", irow, icol, point_to_print.axis, point_to_print.ordinate, point_to_print.altitude);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

// receiving fdf coordinates from a file and placing in a struct matrix of 3d points
void	initialise_and_fill_coordinates_matrix(unsigned int num_rows, unsigned int num_cols)
{
	char		*next_line;
	int			fd;
	char 		**split_line;
	unsigned int	irow;
	unsigned int 	icol;
	point3d matrix[num_rows][num_cols];
	point3d new_point;

	fd = open("test.fdf", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return;
	}
	icol = 0;
	while (1)
	{
		next_line = get_next_line(fd);
		if(next_line == NULL)
			break;
		split_line = ft_split(next_line, ' ');
		irow = 0;
		while(split_line[irow])
		{
			new_point.axis = irow;
			new_point.ordinate = icol;
			if (icol == 1 && irow == 1)
				new_point.altitude = ft_atoi(split_line[irow]);
			else
				new_point.altitude = 0;
			matrix[irow][icol] = new_point;			
			irow++;
		}
		free(next_line);
		icol++;
	}
	print_matrix(num_rows, num_cols, matrix);
}

int main()
{
	unsigned int	num_rows;
	unsigned int	num_cols;
	int				result;

	num_rows = 0;
	num_cols = 0;
	result = get_coordinate_dimensions(&num_rows, &num_cols);
	if (result == -1)
	{
		printf("Error in file: not all rows contain the same number of elements");
		return (-1);
	}
	printf("%u %u\n", num_rows, num_cols);
	initialise_and_fill_coordinates_matrix(num_rows, num_cols);
	return(0);
}

// int main()
// {
// 	int sx = 3, sy = 3; // source
// 	int isx = 0, isy = 0; // indices/counters
// 	int matrix[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
// 	float dx = 0, dy = 0; // destination
// 	int angle = 180;

// 	while(isy < sy)
// 	{
// 		while(isx < sx)
// 		{
// 			int sz = matrix[isx][isy];
// 			dx = isx + cos(angle) * sz - cos(angle) * isy;
// 			dy = -isy * sin(angle) - sz * sin(angle);
// 			printf("%i %i %i: %i %i\n", isx, isy, sz, dx, dy);
// 			isx++;
// 		}
// 		isy++;
// 	}
// }