#include "../0_libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

void	test_ft_putchar_fd(char *path, char c)
{
	int fptr;
	int removed;
	printf("Attempting to put character '%c' in file \"%s\":\n", c, path);
	removed = remove(path);
	if (removed == 0)
		printf("- removed existing file\n");
	fptr = open(path, O_WRONLY | O_CREAT, 0644);
	if (fptr == -1)
		printf("ERROR opening file");
	else
	{
		printf("- succesfully opened new file\n");
		ft_putchar_fd(c, fptr);
		printf("- placed '%c' in it\n", c);
		close(fptr);
		printf("- closed file\n");
	}
	printf("re-reading file to check:\n");
	fptr = open(path, O_RDONLY);
	if (fptr == -1)
		printf("ERROR re-opening file");	
	char *reread = (char *) calloc(100, sizeof(char));
	read(fptr, reread, 10);
	printf("\"%s\"\n\n", reread);
}

int	main()
{
	printf("TEST: Passing a single character...\n");
	test_ft_putchar_fd("/Users/grm/Code/42/cursus/0_libft/ft_putchar_fd-test.txt", 'c');
	printf("TEST: Passing a tab...\n");
	test_ft_putchar_fd("/Users/grm/Code/42/cursus/0_libft/ft_putchar_fd-test.txt", '\t');
	printf("TEST: Passing a terminator '\\0' (i.e. zero)...\n");
	test_ft_putchar_fd("/Users/grm/Code/42/cursus/0_libft/ft_putchar_fd-test.txt", '\0');
	printf("TEST: Passing 127 ('DEL' in ASCII set)\n");
	test_ft_putchar_fd("/Users/grm/Code/42/cursus/0_libft/ft_putchar_fd-test.txt", 127);	
}