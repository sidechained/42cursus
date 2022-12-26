iterate over each char of the format string
- if '%' is found (indicating a conversion) then look for c s p d i u x X directly after and act accordingly
- if % not found, just print the current char

CONVERSIONS
c			
the int argument is converted to an unsigned char, and the resulting character is written.

s
the const char * argument is expected to be a pointer to an array of character type (pointer to a string).  Characters from the array are written up to (but not including) a terminating null byte ('\0'); if a precision is specified, no more than the number specified are written.  If a precision is given, no null byte need be present; if the precision is not specified, or is greater than the size of the array, the array must contain a terminating null byte.

p
The void * pointer argument is printed in hexadecimal (as if by %#x or %#lx).	

d | i
The int argument is converted to signed decimal notation. The precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros.  The default precision is 1.  When 0 is printed with an explicit precision 0, the output is empty.

u | x | X
The unsigned int argument is converted to unsigned decimal (u), or unsigned hexadecimal (x and X) notation. The letters abcdef are used for x conversions; the letters ABCDEF are used for X conversions.  The precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros.  The default precision is 1.  When 0 is printed with an explicit precision 0, the output is empty.

PADDING

FLAGS (BONUS)

• Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.

• Manage all the following flags: ’# +’ (Yes, one of them is a space)

-			
The converted value is to be left adjusted on the field boundary.  (The default is right justification.)  The converted value is padded on the right with blanks, rather than on the left with blanks or zeros.  A - overrides a 0 if both are given.

0		
The value should be zero padded.  For d, i, o, u, x, X, a, A, e, E, f, F, g, and G conversions, the converted value is padded on the left with zeros rather than blanks.  If the 0 and - flags both appear, the 0 flag is ignored.  If a precision is given with a numeric conversion (d, i, o, u, x, and X), the 0 flag is ignored.  For other conversions, the behavior is undefined.

.
An optional precision, in the form of a period ('.')  followed by an optional decimal digit string.  Instead of a decimal digit string one may write "*" or "*m$" (for some decimal integer m) to specify that the precision is given in the next argument, or in the m-th argument, respectively, which must be of type int.  If the precision is given as just '.', the precision is taken to be zero.  A negative precision is taken as if the precision were omitted.  This gives the minimum number of digits to appear for d, i, o, u, x, and X conversions, the number of digits to appear after the radix character for a, A, e, E, f, and F conversions, the maximum number of significant digits for g and G conversions, or the maximum number of characters to be printed from a string for s and S conversions.

#
The value should be converted to an "alternate form".  For o conversions, the first character of the output string is made zero (by prefixing a 0 if it was not zero already). For x and X conversions, a nonzero result has the string "0x" (or "0X" for X conversions) prepended to it.  For a, A, e, E, f, F, g, and G conversions, the result will always contain a decimal point, even if no digits follow it (normally, a decimal point appears in the results of those conversions only if a digit follows).  For g and G conversions, trailing zeros are not removed from the result as they would otherwise be.  For other conversions, the result is undefined.

' '
A blank should be left before a positive number (or empty string) produced by a signed conversion.

+
A sign (+ or -) should always be placed before a number produced by a signed conversion.  By default, a sign is used only for negative numbers.  A + overrides a space if both are used.

// flags code
if (format_str[pos] == '-')
	right_space_pad_len = get_digits(format_str, &pos);
if (format_str[pos] == '0')
	left_zero_pad_len = get_digits(format_str, &pos);
if (format_str[pos] == '.')
	precision = get_digits(format_str, &pos);
if (format_str[pos] == '*')
{
	pos++;
	left_space_pad_len = va_arg(ap, int);
}


