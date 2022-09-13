#include <stdio.h>
#include <string.h>

int main()
{
	char first[] = "This is ";
	char last[] = "a potentially long string";
	int r;
	int r2;
	int size = 16;
	char buffer[size];
	char buffer2[size];

	strcpy(buffer,first);
	r = strlcat(buffer,last,size);
	puts(buffer);
	printf("Value returned: %d\n",r);
	if( r > size )
		puts("String truncated");
	else
		puts("String was fully copied");

	strcpy(buffer2,first);
	r2 = ft_strlcat(buffer2,last,size);
	puts(buffer2);
	printf("Value returned: %d\n",r2);
	if( r2 > size )
		puts("String truncated");
	else
		puts("String was fully copied");

	return(0);
}
