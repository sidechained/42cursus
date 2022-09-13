#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];
	char str2[50];
	int len;

	strcpy(str, "This is tutorialspoint.com");
	len = strlen(str);
	printf("Length of |%s| is |%d|\n", str, len);

	strcpy(str2, "This is tutorialspoint.com");
	len = ft_strlen(str2);
	printf("Length of |%s| is |%d|\n", str2, len);

	return(0);
}