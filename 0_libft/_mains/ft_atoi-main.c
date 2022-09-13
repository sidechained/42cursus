#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   int val;
   int val2;
   char str[20];
   char str2[20];   
   
   strcpy(str, "98993489");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);
   strcpy(str, "tutorialspoint.com");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   strcpy(str2, "98993489");
   val2 = ft_atoi(str2);
   printf("String value = %s, Int value = %d\n", str2, val2);
   strcpy(str2, "tutorialspoint.com");
   val2 = ft_atoi(str2);
   printf("String value = %s, Int value = %d\n", str2, val2);

   return(0);
}