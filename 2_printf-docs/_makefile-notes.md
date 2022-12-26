makefile knowledge

-o	Names the output file
-c	Direct the compiler to suppress linking with ld(1) and to produce a .o file for each source file
-include


Process file as if #include "file" appeared as the first line of the primary source file. However, the first directory searched for file is the preprocessor’s working directory instead of the directory containing the main source file. If not found there, it is searched for in the remainder of the #include "…" search chain as normal.

If multiple -include options are given, the files are included in the order they appear on the command line. 

https://www.geeksforgeeks.org/static-vs-dynamic-libraries/

With libraries you still need header files
You should #include "libstatic.h", i.e. use the appropriate header file in your code (that's why your code doesn't compile) and include the path to your libstatic.a in the linker options as one of your input libraries