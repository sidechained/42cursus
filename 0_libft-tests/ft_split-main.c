// array must be terminated with NULL
// each string in array must be terminated with '\0'
// therefore:
// s "Test Ting" with c ' ' will result into an array of size 3: "Test", "Ting", NULL

#include "libft.h"

void	test_ft_split(char const *s, char c)
{
	char **splits;
	int i;
	printf("Splitting \"%s\" using '%c':\n", s, c);
	splits = ft_split(s, c);
	i = 0;
	while(splits[i])
	{
		printf("split %i:\"%s\"\n", i, splits[i]);
		i++;
	}
}

int	main()
{
	// should splits on start and end result in ""?
	test_ft_split("Test Ting", ' ');
	test_ft_split("Fourty Two", 'o');
	test_ft_split("^ _^_ >^< ^", '^');	
	return (0);
}