#include <stdio.h>
#include <math.h>

// Example:
// 000
// 010
// 000





struct point3d
{
	unsigned int axis;
	unsigned int ordinate;
	int altitude;
};

int main()
{
	// receiving from a file


	// fill struct for 2d array of points
	unsigned int num_rows = 3;
	unsigned int num_cols = 3;
	unsigned int irow = 0;
	unsigned int icol = 0;

	struct point3d point3d_matrix[num_rows][num_cols];
	struct point3d new_point;

	while(icol < num_cols)
	{
		while(irow < num_rows)
		{
			new_point.axis = irow;
			new_point.ordinate = icol;
			if (icol == 1 && irow == 1)
				new_point.altitude = 1;
			else
				new_point.altitude = 0;
			point3d_matrix[irow][icol] = new_point;
			irow++;
		}
		irow = 0;
		icol++;
	}

	// print it back:
	irow = 0;
	icol = 0;
	struct point3d point_to_print;

	while(icol < num_cols)
	{
		while(irow < num_rows)
		{
			point_to_print = point3d_matrix[irow][icol];
			printf("[%u] [%u] %u %u %i\n", irow, icol, point_to_print.axis, point_to_print.ordinate, point_to_print.altitude);
			irow++;
		}
		irow = 0;
		icol++;
	}
};

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
