#include <stdio.h>
#include <math.h>

int main()
{
	int sx = 3, sy = 3; // source
	int isx = 0, isy = 0; // indices/counters
	int matrix[3][3] = {0, 0, 0, 0, 1, 0, 0, 0, 0};
	int dx, dy, dz = 0; // destination
	int angle = 180;

	while(isy < sy)
	{
		while(isx < sx)
		{
			int sz = matrix[isx][isy];
			dx = isx + cos(angle) * sz - cos(angle) * isy;
			dy = -isy * sin(angle) - sz * sin(angle);
			printf("%i %i %i: %i %i\n", isx, isy, sz, dx, dy);
			isx++;
		}
		isy++;
	}
}
