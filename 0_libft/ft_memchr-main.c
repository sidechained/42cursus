#include "libft.h"

void   test_ft_memchr(bool testmode, const void *s, int c, size_t n)
{

   char *ret;
   if (testmode)
      ret = memchr(s, c, n);
   else
      ret = ft_memchr(s, c, n);
   printf("Searching for '%c' in %zu chars of \"%s\"\n", c, n, s);
   printf("Found: \"%s\"\n", ret);
}

void   tests_ft_memchr(bool testmode)
{
   const char s[] = "this test.string.";
   const char c = '.';
   test_ft_memchr(testmode, s, c, strlen(s));

}

int   main(int argc, char **argv)
{
   (void)argc;
   if ((argv[1]) && (strcmp(argv[1],"testmode") == 0))
   {
      printf("--- RUNNING %s [original]\n", argv[0] + 5);
      tests_ft_memchr(true);
   }
   else
   {
      printf("--- RUNNING %s [recoded]\n", argv[0] + 2);
      tests_ft_memchr(false);
   }
   return 0;
}