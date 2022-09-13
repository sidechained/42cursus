#include <stdio.h>
#include <string.h>

int	main ()
{
	char bigString[1000];
	char* end = bigString + sizeof bigString;
	char bigString2[1000];
	char* end2 = bigString2 + sizeof bigString2;
	 	 
	char* p = memccpy(bigString, "John, ", 0, sizeof bigString);
	if (p) p = memccpy(p - 1, "Paul, ", 0, end - p);
	if (p) p = memccpy(p - 1, "George, ", 0, end - p);
	if (p) p = memccpy(p - 1, "Joel ", 0, end - p); 
	puts(bigString); // John, Paul, George, Joel

	char* q = ft_memccpy(bigString2, "John, ", 0, sizeof bigString2);
	if (q) q = ft_memccpy(q - 1, "Paul, ", 0, end2 - q);
	if (q) q = ft_memccpy(q - 1, "George, ", 0, end2 - q);
	if (q) q = ft_memccpy(q - 1, "Joel ", 0, end2 - q);
	puts(bigString2); // John, Paul, George, Joel	
}