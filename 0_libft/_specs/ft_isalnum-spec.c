// The isalnum() and isalnum_l() functions shall test whether c is a
// character of class alpha or digit in the current locale

// The c argument is an int, the value of which the application
// shall ensure is representable as an unsigned char or equal to the
// value of the macro EOF. If the argument has any other value, the
// behavior is undefined.

// The isalnum() and isalnum_l() functions shall return non-zero if
// c is an alphanumeric character; otherwise, they shall return 0.