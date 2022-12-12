#include "../0_libft/libft.h"
#include <stdio.h>

void	test_ft_strchr(bool testmode, const char *s, int c)
{
	 char *ret;
	 if (testmode)
	 	ret = strchr(s, c);
	 else
	 	ret = ft_strchr(s, c);
	 printf("String after '%c' in \"%s\" is \"%s\"\n\n", c, s, ret);
}

void	tests_ft_strchr(bool testmode)
{
	test_ft_strchr(testmode, "http://www.42berlin.de", '.');
   test_ft_strchr(testmode, "looking for a    tab [strange but expected!]", '\t');
   test_ft_strchr(testmode, " looking at beginning", ' ');
   test_ft_strchr(testmode, "lookingAtEnd ", ' ');
   test_ft_strchr(testmode, "", '.');
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_strchr(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_strchr(false);
	}
	return 0;
}