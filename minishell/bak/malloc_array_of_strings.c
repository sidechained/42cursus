#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "ft_substr.c"

char** test()
{
	char** splits = malloc(2 * sizeof(char*));
	splits[0] = "test0";
	splits[1] = "test1";	
	return splits;
}

int main()
{
	char** splits = test();
	printf("%s %s\n", splits[0], splits[1]);
}