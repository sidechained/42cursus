// Applies the function ’f’ to each character of the string ’s’
// to create a new string (with malloc(3)) resulting from successive applications of ’f’.
// #1. The string on which to iterate.
// #2. The function to apply to each character.
// The string created from the successive applications of ’f’. Returns NULL if the allocation fails.
// malloc

// approach:
// count length of s and allocate memory
// iterate over s, applying function, storing result in ret
