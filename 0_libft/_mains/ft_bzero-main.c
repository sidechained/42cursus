#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	char       str[50];
	char       str2[50];

	strcpy(str,"This should be erased by bzero...");	
	puts(str);
	bzero(str,50);
	puts(str);

	strcpy(str2,"This should be erased by bzero...");	
	puts(str2);
	ft_bzero(str2,50);
	puts(str2);

	return(0);
}