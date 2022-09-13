// Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.
// #1. The string from which to create the substring.
// #2. The start index of the substring in the string ’s’.
// #3. The maximum length of the substring.
// The substring. NULL if the allocation fails.
// i.e.
// - if s reaches terminator
// - if len <= 0
// - if start < 0
// - others?
// malloc