// Allocates (with malloc(3)) and returns a copy of ’s1’
// with the characters specified in ’set’ removed from the beginning and the end of the string.
// #1. The string to be trimmed.
// #2. The reference set of characters to trim
// The trimmed string. NULL if the allocation fails.
// malloc

// Approach:
// Find the first char in 's1' that is not in 'set'
// - set this position as 'start'
// Find the last char in 's1' that is not in 'set'
// - set this position as 'end'
// allocate the memory and copy trimmed string into it

// Approach:
// Find the first position in a string that is not in set, set as 'start'
// Find the last position in a string that is not in set, set as 'end'
// malloc 'ret' of size end - start
// iterate over 's1' from start to end, copying into 'ret'
// return 'ret'
// Finding in set done as follows:
// - iterate over string from start
// - if curr_char in set
// 		advance start and advance string index
// - else break