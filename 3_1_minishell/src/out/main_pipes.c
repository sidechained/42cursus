#include "../libft/ft_split.c"

// int main()
// {
// 	char *str = "a_|_b";
// 	char **splits;
// 	splits = ft_split(str, '|');
// 	int i = 0;
// 	while(splits[i])
// 	{
// 		printf("%s\n", splits[i]);
// 		i++;
// 	}
// }

int main()
{
	char *str = "a_\'b\'_c";
	char **splits;
	splits = ft_split(str, '\'');
	int i = 0;
	while(splits[i])
	{
		printf("%s\n", splits[i]);
		i++;
	}
}