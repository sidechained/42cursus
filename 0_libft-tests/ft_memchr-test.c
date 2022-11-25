#include "../0_libft/inc/libft.h"

void   test_ft_memchr(bool testmode, const void *s, int c, size_t n)
{

   char *ret;
   if (testmode)
      ret = memchr(s, c, n);
   else
      ret = ft_memchr(s, c, n);
   printf("Searching for '%c' in %zu chars of \"%s\"\n", c, n, s);
   printf("Found: \"%s\"\n\n", ret);
}

void   tests_ft_memchr(bool testmode)
{
   const char s[] = "this is a test.string.";
   const char c = '.';
   test_ft_memchr(testmode, s, c, strlen(s));
   const char s2[] = "looking for a    tab [strange but expected!]";
   const char c2 = '\t';
   test_ft_memchr(testmode, s2, c2, strlen(s2));
   const char s3[] = " looking at beginning";
   const char c3 = ' ';
   test_ft_memchr(testmode, s3, c3, strlen(s3));
   const char s4[] = "lookingAtEnd ";
   const char c4 = ' ';
   test_ft_memchr(testmode, s4, c4, strlen(s4));
   const char s5[] = "";
   const char c5 = '.';
   test_ft_memchr(testmode, s5, c5, strlen(s5));
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