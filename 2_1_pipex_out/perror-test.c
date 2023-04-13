#include <sys/stat.h> // open
#include <fcntl.h>	  // open
#include <stdlib.h>	  // malloc
#include <errno.h>
#include <stdio.h>


int main()
{	
	printf("%i", errno);	
	open("file.c", O_RDONLY);
	printf("%i", errno);	
	perror("ERRNO");
}