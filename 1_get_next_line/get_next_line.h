#include <stdbool.h> // eventually remove
#include <unistd.h> // read
#include <string.h> // strcmp (remove)
#include <stdlib.h>
#include <limits.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*malloc_empty_string(void);
char	*ft_substr(char const *s, uint start, size_t len);