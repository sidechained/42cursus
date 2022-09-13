// memccpy - copies no more than n bytes from memory area src to memory area dest
// stopping when the character c is found.
// If the memory areas overlap, the results are undefined.
// returns a pointer to the next character in dest after c, or NULL if c was not found in the first n characters of src.