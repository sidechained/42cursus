#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[12] = "TestingTing"; // 11 chars + leaving space for terminator
	char *res;

	printf("Test string =  %s\n", str);
	res = ft_substr(str, 0, 11);
	printf("0, 11: %s\n", res);
	res = ft_substr(str, 0, 5);
	printf("0, 5: %s\n", res);	
	res = ft_substr(str, 4, 5);
	printf("4, 5: %s\n", res);
	res = ft_substr(str, 6, 5);
	printf("6, 5: %s\n", res);
	res = ft_substr(str, 0, 20);
	printf("0, 20: %s\n", res);
	res = ft_substr(str, 4, 20);
	printf("4, 20: %s\n", res);
	res = ft_substr(str, 0, 20);
	printf("0, 20: %s\n", res);
	res = ft_substr(str, 0, 0);
	printf("0, 0: %s\n", res);
	res = ft_substr(str, 0, -5);
	printf("0, -5: %s\n", res);	
	res = ft_substr(str, -2, 11);
	printf("-2, 11: %s\n", res);
	res = ft_substr(str, 0, 12);
	printf("is this expected -> 0, 12: %s\n", res);	
}