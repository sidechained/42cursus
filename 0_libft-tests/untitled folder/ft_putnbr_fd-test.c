#include "../0_libft/inc/libft.h"
#include <fcntl.h>

void	test_ft_putnbr_fd(char *path, int n)
{
	int fptr;
	int removed;
	printf("Attempting to put number %i in file \"%s\":\n", n, path);
	removed = remove(path);
	if (removed == 0)
		printf("- removed existing file\n");
	fptr = open(path, O_WRONLY | O_CREAT, 0644);
	if (fptr == -1)
		printf("ERROR opening file");
	else
	{
		printf("- succesfully opened new file\n");
		ft_putnbr_fd(n, fptr);
		printf("- placed \"%i\" in it\n", n);
		close(fptr);
		printf("- closed file\n");
	}
	printf("re-reading file to check:\n");
	fptr = open(path, O_RDONLY);
	char *reread = (char *) calloc(100, sizeof(char));
	read(fptr, reread, 10);
	printf("\"%s\"\n\n", reread);
}

int	main()
{
	printf("TEST: passing a positive integer...\n");
	test_ft_putnbr_fd("/Users/grm/Code/42/cursus/0_libft/ft_putnbr_fd-test.txt", 12345678);
	printf("TEST: passing zero...\n");
	test_ft_putnbr_fd("/Users/grm/Code/42/cursus/0_libft/ft_putnbr_fd-test.txt", 0);	
	printf("TEST: passing a negative integer...\n");
	test_ft_putnbr_fd("/Users/grm/Code/42/cursus/0_libft/ft_putnbr_fd-test.txt", -12345678);
	printf("TEST: passing a negative integer...\n");
	test_ft_putnbr_fd("/Users/grm/Code/42/cursus/0_libft/ft_putnbr_fd-test.txt", 2147483647);
	printf("TEST: passing a negative integer...\n");
	test_ft_putnbr_fd("/Users/grm/Code/42/cursus/0_libft/ft_putnbr_fd-test.txt", -2147483647);
	// misses last digit
	printf("TEST: passing a negative integer...\n");
	test_ft_putnbr_fd("/Users/grm/Code/42/cursus/0_libft/ft_putnbr_fd-test.txt", -2147483648);
	// misses last digit
}