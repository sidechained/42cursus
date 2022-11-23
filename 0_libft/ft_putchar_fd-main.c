#include "libft.h"
#include <fcntl.h>

void	test_ft_putchar_fd(char *path, char *str)
{
	int fptr;
	int removed;
	printf("Attempting to put string \"%s\" char by char in file \"%s\":\n", str, path);
	removed = remove(path);
	if (removed == 0)
		printf("- removed existing file\n");
	fptr = open(path, O_WRONLY | O_CREAT, 0644);
	if (fptr == -1)
		printf("ERROR opening file");
	else
	{
		printf("- succesfully opened new file\n");
		int i = 0;
		while(str[i])
		{
			ft_putchar_fd(str[i], fptr);
			i++;
		}
		printf("- placed \"%s\" in it\n", str);
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
	test_ft_putchar_fd("/Users/grm/Code/42/cursus/0_libft/ft_putchar_fd-test.txt", "cdef");
}