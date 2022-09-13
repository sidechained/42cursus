// Allocates (with malloc(3)) and returns a string representing the integer received as an argument.
// Negative numbers must be handled.
// #1. the integer to convert.
// The string representing the integer. NULL if the allocation fails.
// fail cases:
// - malloc doesn't allocate?
// malloc

// approach:
// handle negative numbers: allocate one extra char for '-' sign
// count length of integer in chars, and allocate memory
// handle negative numbers
// work backwards through the string, splitting off the individual digits