TODO: implement percent sign properly!
TODO: ints to uints

## FIRST SET (any combo of -0.)

0      The value should be zero padded. For d, i, u, x and X conversions, the converted value is padded on the left with zeros rather than blanks. For c, p, s conversions it is not. If the 0 and - flags both appear, the 0 flag is ignored. If a precision is given with a numeric conversion (d, i, u, x, and X), the 0 flag is ignored. For other conversions, the behavior is undefined.

-      The converted value is to be left adjusted on the field boundary. (The default is right justification.)  The converted value is padded on the right with blanks, rather than on the left with blanks or zeros. A - overrides a 0 if both are given.

.      Precision. An optional precision, in the form of a period ('.') followed by an optional decimal digit string. 

If the precision is given as just '.', the precision is taken to be zero. A negative precision is taken as if the precision were omitted. 

This gives the minimum number of digits to appear for d, i, o, u, x, and X conversions, the number of digits to appear after the radix character for a, A, e, E, f, and F conversions, the maximum number of significant digits for g and G conversions, or the maximum number of characters to be printed from a string for s and S conversions.

Instead of a decimal digit string one may write "*" or "*m$" (for some decimal integer m) to specify that the precision is given in the next argument, or in the m-th argument, respectively, which must be of type int.

## SECOND SET

- #      For x and X conversions, a nonzero result has the string "0x" (or "0X" for X conversions) prepended to it.

- ' '    (a space) A blank should be left before a positive number (or empty string) produced by a signed conversion.

- +      A sign (+ or -) should always be placed before a number produced by a signed conversion. By default, a sign is used only for negative numbers. A + overrides a space if both are used.

## IN GENERAL

flags follow the %

we need to look ahead to see if the flag is appropriate to the conversion
so we just set flags, and then later in the conversion functions see if they apply

how about a struct for flags

