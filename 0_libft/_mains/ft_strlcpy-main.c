#include <stdio.h>
#include <string.h>

void test(int size)
{
	char string[] = "Hello there, Venus";
	char buffer[19];
	char buffer2[19];
	int r;
	int r2;

	r = strlcpy(buffer,string,size);
	printf("Copied '%s' into '%s', length %d\n",
		string,
		buffer,
		r
	);

	r2 = ft_strlcpy(buffer2,string,size);
	printf("Copied '%s' into '%s', length %d\n",
		string,
		buffer2,
		r2
	);
}

int main()
{
    test(19);
    test(10);
    test(1);
    test(0);

    return(0);
}
