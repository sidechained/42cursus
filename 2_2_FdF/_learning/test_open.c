#include <stdio.h>
#include <fcntl.h> // open

int main()
{
	char *filename;
	int		fd;

	filename = "test.fdf";

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (-1);
	}
	printf("opened!\n");
}