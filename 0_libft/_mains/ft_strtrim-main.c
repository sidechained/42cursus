#include <stdio.h>

int main()
{
	char *s1 = "abcnother funa";
	char *set = "abc";
	char *res;

	res = ft_strtrim(s1, set);
	printf("str:%s\nset:%s\nresult:%s\n", s1, set, res);
}