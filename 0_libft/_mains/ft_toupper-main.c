#include <stdio.h>
#include <ctype.h>

int main () {
       int i;
       char str[] = "Tutorials Point";

       i = 0;
       while(str[i]) {
              putchar (toupper(str[i]));
              i++;
       }
       putchar('\n');

       i = 0;
       while(str[i]) {
              putchar (ft_toupper(str[i]));
              i++;
       }
       putchar('\n');       

       return(0);
}