#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fptr;
	char *path;	
	
	path = "/Users/grm/Desktop/42cursus/0_libft/32_ft_putnbr_fd-test.txt";	
	remove(path);	
	fptr = open(path, O_WRONLY | O_CREAT, 0644);
	ft_putnbr_fd(-12345678, fptr);
	close(fptr);
}
