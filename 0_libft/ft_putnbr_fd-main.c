#include "libft.h"
#include <fcntl.h>

void	test_ft_putnbr_fd(char *path, int n)
{
	int fptr;
	int removed;
	printf("Attempting to put number \"%i\" in file \"%s\":\n", n, path);
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
	printf("- now executing 'cat' on resulting file to check:\n");
	char *args[] = {"cat", path};
	char *envp[] = { 0 };	/* leave the environment list null */
	execve("/bin/cat", args, envp);
	perror("execve");
}

int	main()
{
	test_ft_putnbr_fd("/Users/grm/Code/42/cursus/0_libft/ft_putnbr_fd-test.txt", -12345678);
}