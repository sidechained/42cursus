#include <stdio.h>

typedef struct point3d
{
	unsigned int axis;
} point3d;

void	print_matrix(unsigned int num_rows, unsigned int num_cols, point3d matrix[num_rows][num_cols])
{
	unsigned int	i_rows = 0;
	unsigned int	i_cols = 0;

	while(i_cols < num_rows)
	{
		while(i_rows < num_rows)
		{
			printf("[%u %u] %u\n", i_rows, i_cols, matrix[i_rows][i_cols].axis);
			i_rows++;
		}
		i_rows = 0;
		i_cols++;
	}
}

int main()
{
	point3d	matrix[2][2];
	matrix[0][0].axis = 1;
	matrix[0][1].axis = 2;
	matrix[1][0].axis = 3;
	matrix[1][1].axis = 4;

	print_matrix(2, 2, matrix);
}