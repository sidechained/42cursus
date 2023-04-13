// mallocing approach

#include <stdio.h>
#include <stdlib.h>

int** createArray(int nrows, int ncols)
{
    int* values = calloc(nrows*ncols, sizeof(int)); // enough memory for all the values
    int** rows = malloc(nrows*sizeof(int*)); // these are pointers to ints (existing ones?)
    for (int i=0; i<nrows; ++i)
    {
        rows[i] = values + i*ncols; // increment the values pointer 
    }
    return rows;
}

void destroyArray(int** arr)
{
    free(*arr);
    free(arr);
}

void printArray(int** coords, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < nrows)
	{
		while(irow < ncols)
		{
			printf("[%i][%i] %i\n", irow, icol, *(coords[irow] + icol));
			irow++;
		}
		irow = 0;
		icol++;
	}
}

int main(void)
{
    int** arr = createArray(2,2);
    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[1][0] = 30;
    arr[1][1] = 40;
    printArray(arr, 2, 2); 
    destroyArray(arr);
}