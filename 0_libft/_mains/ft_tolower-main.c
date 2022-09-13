#include <stdio.h>
#include <ctype.h>

int main () {
	int i;
	char str[] = "TUTORIALS POINT";

	i = 0;
	while( str[i] ) {
		putchar(tolower(str[i]));
		i++;
	}
	putchar('\n');

	i = 0;
	while( str[i] ) {
		putchar(ft_tolower(str[i]));
		i++;
	}
	putchar('\n');

	return(0);
}