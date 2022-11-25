#include "../0_libft/inc/libft.h"

void	test_ft_strlen(bool testmode, const char *s)
{
	int len;
	if(testmode)
		len = strlen(s);
	else
		len = ft_strlen(s);
	printf("Length of \"%s\" is %d\n\n", s, len);
}

void	tests_ft_strlen(bool testmode)
{
	test_ft_strlen(testmode, "Stringy McStringface");
	test_ft_strlen(testmode, "");
	test_ft_strlen(testmode, "\t\n ");
	test_ft_strlen(testmode, "TERMINATOR\0AFTER");
	test_ft_strlen(testmode, "REALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYREALLYLONG");
}

int	main(int argc, char **argv)
{
	(void)argc;
	if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
	{
		printf("--- RUNNING %s [original]\n", argv[0] + 5);
		tests_ft_strlen(true);
	}
	else
	{
		printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
		tests_ft_strlen(false);
	}
	return 0;
}