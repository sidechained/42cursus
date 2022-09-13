#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *res;
	const char *str1 = "Testing";
	const char *str2 = "Ting";
	const char *str3 = "";
	const char *str4 = "";
	const char *str5 = NULL;
	const char *str6 = NULL;	

	res = ft_strjoin(str1, str2);
	printf("%s %s: %s\n", str1, str2, res);

	res = ft_strjoin(str3, str4);
	printf("%s %s: %s\n", str3, str4, res);	

	res = ft_strjoin(str5, str6);
	printf("%s %s: %s\n", str5, str6, res);		
}