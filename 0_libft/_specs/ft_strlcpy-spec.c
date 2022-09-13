// A simple implementation of strncpy() might be:

// char *
// strncpy(char *dest, const char *src, size_t n)
// {
//    size_t i;

//    for (i = 0; i < n && src[i] != '\0'; i++)
//        dest[i] = src[i];
//    for ( ; i < n; i++)
//        dest[i] = '\0';

//    return dest;
// }
// The strcpy() and strncpy() functions return a pointer to the
// destination string dest.

// strlcpy()
// This function is similar to strncpy(), but it copies at most
// size-1 bytes to dest, always adds a terminating null byte, and
// does not pad the destination with (further) null bytes.  This
// function fixes some of the problems of strcpy() and strncpy(),
// but the caller must still handle the possibility of data loss if
// size is too small.  The return value of the function is the
// length of src, which allows truncation to be easily detected: if
// the return value is greater than or equal to size, truncation
// occurred.  If loss of data matters, the caller must either check
// the arguments before the call, or test the function return value.
// strlcpy() is not present in glibc and is not standardized by
// POSIX, but is available on Linux via the libbsd library.