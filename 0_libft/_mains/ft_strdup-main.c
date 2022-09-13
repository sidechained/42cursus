#include <stdio.h>
#include <string.h>

int main() {
	char *str = "Helloworld";
	char *result;
	char *result2;

	result = strdup(str);
	printf("The string : %s\n", result);

	result2 = ft_strdup(str);
	printf("The string : %s\n", result2);

	return 0;
}