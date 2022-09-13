// locates the first occurrence of the null-terminated string little in the string big
// where not more than len characters are searched.
// Characters that appear after a '\0' character are not searched.

// If little is an empty string, big is returned
// if little occurs nowhere in big, NULL is returned
// otherwise a pointer to the first character of the first occurrence of little is returned.