#include <stdio.h>
#include <string.h>

int	main ()
{
	const char	src[50] = "http://www.tutorialspoint.com";
	char		dest[50];
	char		dest2[50];	

	strcpy (dest,"Heloooo!!");
	printf ("Before memcpy dest = %s\n", dest);
	memcpy (dest, src, strlen(src)+1);
	printf ("After memcpy dest = %s\n", dest);

	strcpy (dest2,"Heloooo!!");
	printf ("Before memcpy dest = %s\n", dest2);
	ft_memcpy (dest2, src, strlen(src)+1);
	printf ("After memcpy dest = %s\n", dest2);

	return (0);
}