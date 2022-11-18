### Libft Cheat Sheet: A concise reference for libft functions

#### Libc Functions

[__memset__](https://man7.org/linux/man-pages/man3/memset.3.html) `void *memset(void *s, int c, size_t n);`  
Fill the first _n_ bytes of the memory area pointed to by _s_ with the constant byte _c_

[__bzero__](https://man7.org/linux/man-pages/man3/bzero.3.html) `void bzero(void *s, size_t n);`  
Write `\0`'s to the _n_ bytes of the memory starting at the location pointed to by _s_

[__memcpy__](https://man7.org/linux/man-pages/man3/memcpy.3.html) `void *memcpy(void *restrict dest, const void *restrict src, size_t n);`  
Copy _n_ bytes from memory area _src_ to memory area _dest_. The memory areas must not overlap

[__memccpy__](https://man7.org/linux/man-pages/man3/memccpy.3.html) `void *memccpy(void *restrict dest, const void *restrict src, int c, size_t n);`  
Copy no more than n bytes from memory area _src_ to memory area _dest_, stopping when the char _c_ is found

[__memmove__](https://man7.org/linux/man-pages/man3/memmove.3.html) `void *memmove(void *dest, const void *src, size_t n);`  
Copy n bytes from memory area src to memory area dest. The memory areas may overlap.

[__memchr__](https://man7.org/linux/man-pages/man3/memchr.3.html) `void *memchr(const void *s, int c, size_t n);`  
Scan the initial n bytes of the memory area pointed to by s for the first instance of c.

[__memcmp__](https://man7.org/linux/man-pages/man3/memcmp.3.html) `int memcmp(const void *s1, const void *s2, size_t n);`  
!Compare memory areas _s1_ and _s2_, returning 0 if they are equal, negative if _s1_ < _s2_ and positive if _s1_ > _s2_

[__strlen__](https://man7.org/linux/man-pages/man3/strlen.3.html) `size_t strlen(const char *s);`  
Return the length of the string pointed to by s, excluding the terminating null byte (`\0`).

[__strlcpy__](https://man7.org/linux/man-pages/man3/strcpy.3.html) `size_t strlcpy(char *dest, const char *src, size_t size);`  
Copy up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result

[__strlcat__](https://man7.org/linux/man-pages/man3/strcat.3.html) `size_t strlcat(char *dest, const char *src, size_t size);`  
Append at most (size - strlen(dst) - 1) bytes of the NUL-terminated string src to the end of dst, NUL-terminating the result.

[__strchr__](https://man7.org/linux/man-pages/man3/strchr.3.html) `char *strchr(const char *s, int c);`  
Return a pointer to the first occurrence of the character c in the string s

[__strrchr__](https://man7.org/linux/man-pages/man3/strchr.3.html) `char *strrchr(const char *s, int c);`  
Return a pointer to the last occurrence of the character c in the string s

[__strnstr__](https://www.freebsd.org/cgi/man.cgi?query=strnstr&sektion=3) `char *strnstr(const char *big, const char *little, size_t len);`  
Search _len_ characters, locating the first occurrence of the null-terminated string _little_ in the string _big_

[__strncmp__](https://man7.org/linux/man-pages/man3/strcmp.3.html) `int strncmp(const char *s1, const char *s2, size_t n);`  
Compare (at most) the first n bytes of _s1_ and _s2_, returning 0 if they are equal, negative if _s1_ < _s2_ and positive if _s1_ > _s2_

[__atoi__](https://man7.org/linux/man-pages/man3/atoi.3.html) `int atoi(const char *nptr);`  
Convert the initial portion of the string pointed to by _nptr_ to int

[__isdigit__](https://man7.org/linux/man-pages/man3/isdigit.3p.html) `int isdigit(int c);`  
Test whether character _c_ is of class digit

[__isalnum__](https://man7.org/linux/man-pages/man3/isalnum.3p.html) `int isalnum(int c);`  
Test whether character _c_ is alphanumeric

[__isascii__](https://man7.org/linux/man-pages/man3/isascii.3p.html) `int isascii(int c);`  
Test whether character _c_ is a 7-bit US-ASCII character code

[__isprint__](https://man7.org/linux/man-pages/man3/isprint.3p.html) `int isprint(int c);`  
!Test whether character _c_ is printable

[__toupper__](https://man7.org/linux/man-pages/man3/toupper.3.html) `int toupper(int c);`  
Convert a lowercase letter to uppercase, returning _c_ in case of non-conversion

[__tolower__](https://man7.org/linux/man-pages/man3/tolower.3p.html) `int tolower(int c);`  
Convert a uppercase letter to lowercase, returning _c_ in case of non-conversion

[__calloc__](https://man7.org/linux/man-pages/man3/calloc.3p.html) `void *calloc(size_t nelem, size_t elsize);`  
Allocate and zero-initialise a block of memory of _nelem_ elements, each _elsize_ bytes long

[__strdup__](https://man7.org/linux/man-pages/man3/strdup.3.html) `char *strdup(const char *s);`  
Allocate and return a pointer to a new string which is a duplicate of the string s

#### Additional Functions

__ft_substr__ `char *ft_substr(char const *s, unsigned int start, size_t len);`  
Allocate and return a substring from the string ’s’ at index ’start’ and of max size ’len’

__ft_strjoin__ `char *ft_strjoin(char const *s1, char const *s2);`  
Allocate and return a new string, which is the result of the concatenation of _s1_ and _s2_

__ft_strtrim__ `char *ft_strtrim(char const *s1, char const *set);`  
Allocate and return a copy of _s1_ with the characters specified in _set_ removed from the start and end

__ft_split__ `char **ft_split(char const *s, char c);`  
Allocate and return a NUL-terminated array of strings by splitting _s_ using the character _c_ as a delimiter

__ft_itoa__ `char *ft_itoa(int n);`  
Allocate and return an ascii string representing the integer _n_

__ft_strmapi__ `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`  
Successively apply the function _f_ to each character of the string _s_ to create a new string

__ft_putchar_fd__ `void ft_putchar_fd(char c, int fd);`  
Output the character _c_ to the given file descriptor.

__ft_putstr_fd__ `void ft_putstr_fd(char *s, int fd);`  
Output the string _s_ to the given file descriptor.

__ft_putendl_fd__ `void ft_putendl_fd(char *s, int fd);`  
Outputs the string _s_ to the given file descriptor, followed by a newline.

__ft_putnbr_fd__ `void ft_putnbr_fd(int n, int fd);`  
Outputs the integer _n_ to the given file descriptor.