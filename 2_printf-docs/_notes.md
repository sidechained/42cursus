allowed: malloc, free, write, va_start, va_arg, va_copy, va_end, anything from libft

`int ft_printf(const char *, ...);`

Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
• Your libftprintf.a has to be created at the root of your repository.

- variadic functions means the 'va'
- Variadic functions are functions that can take a variable number of arguments. In C programming, a variadic function adds flexibility to the program. It takes one fixed argument and then any number of arguments can be passed. The variadic function consists of at least one fixed variable and then an ellipsis(…) as the last parameter.
- https://www.geeksforgeeks.org/variadic-functions-in-c/

- TODO: finish ft_convert_xX (i.e. get to work with flags)
- TODO: split into separate files - ft_printf.c utility_functions.c tests.c (main.c), header.h
- TODO: make makefile to make library libftprintf.a (must use the command ar)
- Q: do I have to use malloc and free?
- TODO: remove char[100] and replace with something far better
- TODO: remove standard functions and replace with ones from libft
- TODO: run norminette on code to pass The Norm
- TODO: does it do this: It will manage any combination of 4 flags and minimum field width with all conversions
-- sprintf - used in u and di functions to convert integer () into str
-- strlen - get length of string
-- isdigit

- make good tests
