#include "../0_libft/libft.h"
#include <bsd/string.h>
#include <stdio.h>

void  test_ft_strncmp(bool testmode, char *str1, char *str2, size_t size)
{
	char trunc_str1[size];
	char trunc_str2[size];
	int ret;
	strlcpy(trunc_str1, str1, size+1);
	strlcpy(trunc_str2, str2, size+1);	
	printf("Comparing first %zi characters of \"%s\" and \"%s\"\n", size, str1, str2);
	if (testmode)
		ret = strncmp(str1, str2, size);
	else
		ret = ft_strncmp(str1, str2, size);
	if(ret < 0)
		printf("RESULT: str1 [\"%s\"] is less than str2 [\"%s\"]", trunc_str1, trunc_str2);
	else if(ret > 0)
		printf("RESULT: str2 [\"%s\"] is less than str1 [\"%s\"]", trunc_str1, trunc_str2);
	else
		printf("RESULT: str1 [\"%s\"] is equal to str2 [\"%s\"]", trunc_str1, trunc_str2);
	printf("\n\n");
}

void  tests_ft_strncmp(bool testmode)
{
	test_ft_strncmp(testmode, "abcdef", "ABCDEF", 4);
	test_ft_strncmp(testmode, "abcdef", "ABCDEF", 8);
	test_ft_strncmp(testmode, "abcdef", "ABCDEF", 0);
	test_ft_strncmp(testmode, "A", "A", 1);	
	test_ft_strncmp(testmode, "A", "A", 2);
}

int   main(int argc, char **argv)
{
   (void)argc;
   if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
   {
      printf("--- RUNNING %s [original]\n", argv[0] + 5);
      tests_ft_strncmp(true);
   }
   else
   {
      printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
      tests_ft_strncmp(false);
   }
   return 0;
}