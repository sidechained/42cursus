#include <stdio.h>
#include <string.h>

int main ()
{
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;
   char *ret2;   

   ret = memchr(str, ch, strlen(str));
   printf("String after |%c| is - |%s|\n", ch, ret);

   ret2 = ft_memchr(str, ch, strlen(str));
   printf("String after |%c| is - |%s|\n", ch, ret2);

   return(0);
}