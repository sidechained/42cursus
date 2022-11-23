#include "libft.h"

void   test_ft_memmove(bool testmode, void *dest, const void *src, size_t n)
{
   printf("BEFORE: dest = %s, src = %s\n", dest, src);
   if(testmode)
      memmove(dest, src, n);
   else
      ft_memmove(dest, src, n);
   printf("AFTER:  dest = %s, src = %s\n", dest, src);
}

void   tests_ft_memmove(bool testmode)
{
   char dest[] = "oldstring";
   const char src[]  = "newstring";
   test_ft_memmove(testmode, dest, src, 9);
}

int   main(int argc, char **argv)
{
   (void)argc;
   if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
   {
      printf("--- RUNNING %s [original]\n", argv[0] + 5);
      tests_ft_memmove(true);
   }
   else
   {
      printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
      tests_ft_memmove(false);
   }
   return 0;
}