#include <stdio.h>
#include <string.h>

int main () {
       const char str[] = "http://www.tutorialspoint.com";
       const char ch = '.';
       const char ch2 = '\0';       
       char *ret1;
       char *ret2;
       char *ret3;
       char *ret4;       

       printf("standard test with char '.':\n");
       ret1 = strchr(str, ch);
       printf("String after |%c| is - |%s|\n", ch, ret1);
       ret2 = ft_strchr(str, ch);
       printf("String after |%c| is - |%s|\n", ch, ret2);

       printf("terminator test with char '\\0':\n");
       ret3 = strchr(str, ch2);
       printf("String after |%c| is - |%s|\n", ch, ret3);
       ret4 = ft_strchr(str, ch2);
       printf("String after |%c| is - |%s|\n", ch, ret4);

       return(0);
}