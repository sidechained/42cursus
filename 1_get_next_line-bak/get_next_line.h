#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

// # if BUFFER_SIZE > 9223372036854775806
// #  undef BUFFER_SIZE
// #  define BUFFER_SIZE 0
// # endif

char	*get_next_line(int fd);

#endif