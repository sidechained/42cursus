#include "../0_libft/inc/libft.h"
#include <fcntl.h>

void	test_ft_putendl_fd(char *path, char *str)
{
	int fptr;
	int removed;
	printf("Attempting to put string \"%s\" in file \"%s\":\n", str, path);
	removed = remove(path);
	if (removed == 0)
		printf("- removed existing file\n");
	fptr = open(path, O_WRONLY | O_CREAT, 0644);
	if (fptr == -1)
		printf("ERROR opening file");
	else
	{
		printf("- succesfully opened new file\n");
		ft_putendl_fd(str, fptr);
		printf("- placed \"%s\" in it\n", str);
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
	printf("TEST: Passing a multicharacter string...\n");
	test_ft_putendl_fd("/Users/grm/Code/42/cursus/0_libft/ft_putstr_fd-test.txt", "cdef");
	printf("TEST: Passing an empty string...\n");
	test_ft_putendl_fd("/Users/grm/Code/42/cursus/0_libft/ft_putstr_fd-test.txt", "");
	printf("TEST: Passing a string consisting only of whitespace...\n");
	test_ft_putendl_fd("/Users/grm/Code/42/cursus/0_libft/ft_putstr_fd-test.txt", " \t\n \t\n");	
	printf("TEST: Passing NULL - should this be handled or is segfault OK?!\n");
	test_ft_putendl_fd("/Users/grm/Code/42/cursus/0_libft/ft_putstr_fd-test.txt", NULL);	
}