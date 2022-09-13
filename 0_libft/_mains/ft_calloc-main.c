#include <stdlib.h>
#include <stdio.h>

int main () {
       int i, n;
       int *a;
       int *b;       

       n = 5;

       a = (int*)calloc(n, sizeof(int));
       for( i=0 ; i < n ; i++ ) {
              a[i] = i;
       }
       for( i=0 ; i < n ; i++ ) {
              printf("%d ",a[i]);
       }
       printf("\n");
       free( a );

       b = (int*)ft_calloc(n, sizeof(int));
       for( i=0 ; i < n ; i++ ) {
              b[i] = i;
       }
       for( i=0 ; i < n ; i++ ) {
              printf("%d ",b[i]);
       }
       printf("\n");
       free( b );

       return(0);
}