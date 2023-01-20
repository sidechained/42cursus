#include <stdio.h>

static void		print_array(char **a)
{
	int i = 0;
	while(a[i])
	{
		printf("%i, %s\n", i, a[i]);
		i++;
	}
}

int main()
{
	char **a = NULL;
	a = ft_split("linkyomatic", 'o');
	print_array(a);
}