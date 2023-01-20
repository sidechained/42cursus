#include "../0_libft/libft.h"
#include <stdio.h>

void   test_ft_memmove(bool testmode, void *dest, const void *src, size_t n)
{
   printf("Copying %zu chars of source string \"%s\"\n", n, (char *)src);
   printf("BEFORE: dest = \"%s\"\n", (char *)dest);
   if(testmode)
      memmove(dest, src, n);
   else
      ft_memmove(dest, src, n);
   printf("AFTER:  dest = \"%s\"\n", (char *)dest);
   printf("\n");
}

void   tests_ft_memmove(bool testmode)
{
   // how to test with overlapping memory
   char dest[] = "oldstring";
   const char src[] = "movedmemy";
   test_ft_memmove(testmode, dest, src, 9);
   char dest2[] = "oldstring";
   const char src2[] = "movedmemy";
   test_ft_memmove(testmode, dest2, src2, 3); 
   char dest3[] = "oldstring";
   const char src3[] = "movedmemy";
   test_ft_memmove(testmode, dest3, src3, 30);
   char dest4[] = "oldstring";
   const char src4[] = "";
   test_ft_memmove(testmode, dest4, src4, 9);
   char dest5[] = "oldstring";
   const char *src5 = dest5 + 1; // overlapping memory
   test_ft_memmove(testmode, dest5, src5, 8);
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