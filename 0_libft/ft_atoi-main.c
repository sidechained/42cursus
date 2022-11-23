#include "libft.h"

void  test_ft_bzero(bool testmode, char *str)
{
   int val;
   if(testmode)
   	val = atoi(str);
   else
   	val = ft_atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);
}

void  tests_ft_bzero(bool testmode)
{
	test_ft_bzero(testmode, "98993489");
	test_ft_bzero(testmode, "berlin.de");
	test_ft_bzero(testmode, "42berlin.de");
}

int   main(int argc, char **argv)
{
   (void)argc;
   if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
   {
      printf("--- RUNNING %s [original]\n", argv[0] + 5);
      tests_ft_bzero(true);
   }
   else
   {
      printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
      tests_ft_bzero(false);
   }
   return 0;
}