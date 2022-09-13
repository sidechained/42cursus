#include <stdio.h>
#include <string.h>

int main ()
{
     const char *largestring = "Foo Bar Baz";
     const char *smallstring = "Bar";
     char *ptr;
     char *ptr2;     

     ptr = strnstr(largestring, smallstring, 11);
     printf("%s\n", ptr);
     ptr = strnstr(largestring, smallstring, 4);
     printf("%s\n", ptr); 

     ptr2 = strnstr(largestring, smallstring, 11);
     printf("%s\n", ptr2);
     ptr2 = strnstr(largestring, smallstring, 4);
     printf("%s\n", ptr2);     
}