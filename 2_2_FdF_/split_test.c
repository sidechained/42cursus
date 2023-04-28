// cc -Wall -Werror -Wextra -Ilibft split_test.c libft/ft_split.c libft/ft_substr.c libft/ft_strlen.c && ./valgrind --leak-check=full ./a.out

#include "libft.h"

int main()
{
	char **ret;
	int i;

	ret = ft_split("test ing", ' ');
	i = 0;
	while(ret[i] != NULL)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (0);
}