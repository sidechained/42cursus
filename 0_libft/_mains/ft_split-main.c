// array must be terminated with NULL
// each string in array must be terminated with '\0'
// therefore:
// str "Test Ting" with sep ' ' will result into an array of size 3: "Test", "Ting", NULL

#include <stdio.h>

int	main()
{
	char *str;
	char sep;
	char **splits;
	int i;

	str = "Test Ting";
	sep = ' ';
	printf("str=\"%s\"\nsep='%c'\n", str, sep);
	splits = ft_split(str, sep);
	i = 0;
	while(splits[i] != NULL)
	{
		printf("split %i:%s\n", i, splits[i]);
		i++;
	}
}