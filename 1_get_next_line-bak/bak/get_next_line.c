#include <stdio.h> // printf
#include <fcntl.h> // open
#include <stdlib.h> // malloc
#include <unistd.h> // read
#include <errno.h>
#include <string.h>

// to detect nl's in chunks
char	*ft_strchr(const char *s, int c)
{
	char	*s_cpy;
	size_t	i;

	s_cpy = (char *)s;
	i = 0;
	while (s_cpy[i] != '\0')
	{
		if (s_cpy[i] == (char)c)
			return (&s_cpy[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s_cpy[i + 1]);
	return (NULL);
}

// to join current chunk to saved chunk
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	l1;
	unsigned int	l2;
	char			*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = 0;
	while (s1[l1] != '\0')
		l1++;
	l2 = 0;
	while (s2[l2] != '\0')
		l2++;
	ret = malloc(sizeof(char) * (l1 + l2));
	l2 = 0;
	while (s1[l2++] != '\0')
		ret[l2] = s1[l2];
	l2 = 0;
	while (s2[l2++] != '\0')
		ret[l1 + l2] = s2[l2];
	return (ret);
}

// extracts line from 'raw_line', by keeping everything up to nl
char *extract_line_from_raw_line(char *raw_line)
{
	char *line;
	int len;
	int i;

	len = 0;
	while(raw_line[len] != '\n')
		len++;
	// printf("line len: %i\n", len);
	line = malloc(sizeof(char) * len + 1);
	i = 0;
	while(i < len)
	{
		line[i] = raw_line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// extracts leftover string from 'raw_line', by keep everything following nl
char *extract_leftover_line_from_raw_line(char *raw_line)
{
	char *leftover_line;
	int len;
	int i;

	while(*raw_line != '\n')
		raw_line++;
	raw_line++;
	len = 0;
	while(raw_line[len] != '\0')
		len++;
//	printf("leftover line len: %i\n", len);
	leftover_line = malloc(sizeof(char) * len + 1);
	i = 0;
	while(i < len)
	{
		leftover_line[i] = raw_line[i];
		i++;
	}
	leftover_line[i] = '\0';
	return (leftover_line);
}

// takes in leftover_line from previous saved line (initially empty)
// reads chunk of size buffer_size from file until newline or EOL found in chunk
// concatenates chunks into single returned string 'raw_line' (including nl and whatever follows up until end of chunk)
int read_raw_line(int fd, char *line)
{
	int buffer_size;
	int num_bytes_read;
	char *chunk;

	buffer_size = 4;
	chunk = malloc(sizeof(char) * buffer_size);
	while(!ft_strchr(chunk, '\n')) // read until nl found in chunk
	{
		num_bytes_read = read(fd, chunk, buffer_size);
		// printf("chunk: \"%s\", ", chunk);
		//	 printf("num_bytes_read: %i\n", num_bytes_read);		
		if (num_bytes_read == -1) // error
			return(-1);
		line = strcat(line, chunk); // my str_join is broken (use strcat)
		if (num_bytes_read < buffer_size) // means EOF reached
			return (0);
	}
	return (1);
}


// CODED FOR NOW THE OLD WAY i.e. no **line parameter, just fd)
// fills the buffer **line with the next line from the file (without nl)
// 'line' is a pointer to pointer because it will be an array of strings representing the whole file
// (it should be called lines?!)
// returns 1, 0, -1 (nl, EOF, error)
int get_next_line(int fd)
{
	int status;
	static char *raw_line = NULL;
	char *line;
	char *leftover_line;

	status = read_raw_line(fd, raw_line);

	if (status == -1)
	{
		printf("Error reading file!\n");
		return (-1);
	}
	line = extract_line_from_raw_line(raw_line);
	leftover_line = extract_leftover_line_from_raw_line(raw_line);
	return(status);
}

int	main()
{
	int fd;
	char *path;
	int status;

	path = "testfile.txt";
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return(0); // correct?
	status = 1;	
	while(status != 0) // read until EOF
	{
		status = get_next_line(fd);
	}
	close(fd);
}