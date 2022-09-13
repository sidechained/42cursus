#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char *str;

	str = ft_itoa(9876);
	printf("%s\n", str);
	str = ft_itoa(-9876);
	printf("%s\n", str);	
}