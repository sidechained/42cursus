#include <stdio.h>
#include <string.h>

int main ()
{
   char       str[50];
   char       str2[50];

   strcpy(str,"This is string.h library function");
   puts(str);
   memset(str,'$',7);
   puts(str);

   strcpy(str2,"This is string.h library function");
   puts(str2);
   ft_memset(str2,'$',7);
   puts(str2);

   return (0);
}