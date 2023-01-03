#include <stdio.h> // printf
#include <fcntl.h> // open
#include <stdlib.h> // malloc
#include <unistd.h> // read
#include <string.h> // strchr

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	(void) argv;

	if (argc != 2)
	{
		printf("Wrong number of arguments provided.\n");
		return (0);
	}
	fd = open("testfile.txt", O_RDONLY); // argv[1]
	if (fd == -1)
	{
		printf("Error reading file.\n");
		return (0);
	}
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);		
	}
	return(0);
}

void read_raw_line(int fd, char **raw_line, char **tmp)
{
	int buffer_size;
	int num_bytes_read;
	char *chunk;

	buffer_size = 4;	
	chunk = malloc(sizeof(char) * (buffer_size + 1));
	num_bytes_read = read(fd, chunk, buffer_size);
	// while(!strchr(chunk, '\n')) // read until nl found in chunk
	// {
	// 	num_bytes_read = read(fd, chunk, buffer_size);
	// 	if (num_bytes_read == -1) // error
	// 		return(NULL);
	// 	*raw_line = strcat(*raw_line, chunk); // my str_join is broken (use strcat)
	// 	if (num_bytes_read < buffer_size) // means EOF reached
	// 		return (NULL);
	// }
	chunk[num_bytes_read] = '\0';
	*tmp = strdup(*raw_line);
	free(*raw_line);
//	*raw_line = strcat(*tmp, chunk);
	printf("%s\n",chunk);
}

char	*get_next_line(int fd)
{
	static char *raw_line = NULL;
	char *tmp = NULL;
//	char *line;
//	char *leftover_line;

	read_raw_line(fd, &raw_line, &tmp);
	//line = extract_line_from_raw_line(raw_line);
	//leftover_line = extract_leftover_line_from_raw_line(raw_line);
	return(raw_line);
}