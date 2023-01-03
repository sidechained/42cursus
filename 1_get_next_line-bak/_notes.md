## CLEAR RETHINK

 Calling your function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.

Read line: correct behavior
NULL: nothing else to read or an error occurred

pull raw_lines from file, until there are no more (NULL)


extract_line_from_raw_line
extract_leftover_line_from_raw_line

read_raw_line:

read the raw_line in chunks (of buffer_size)
do the following until a newline is found in chunk:
	read the next chunk from the file descriptor
	concatenate the new chunk onto the end of raw_line
	count the number of bytes read and:
		if -1: return NULL (error)
		if num_bytes < buffer_size: return NULL (EOF)

copy raw_line into *tmp


//


while()



## NEW NOTES

# get_next_line approach notes

key point: a static variable is necessary to store the extra characters read after a newline

Q: must static variable KEEP be declared and initialised outside read_line function and passed in?
A: 

get_next_line()
{
	loop while line != NULL
	{
		line = read_line
	}
}

read_line()
{
	allocate memory of size BUFFER_SIZE + 1, call this BUF

	loop while num_bytes_read > 0
	{
		read next BUFFER_SIZE chars from file, store in BUF

		if \n found in KEEP:
			extract the part up to and including the \n to return it as LINE
			save the rest of the characters in KEEP
	}

}



when read return 0 it means we are at the end of the file

get_next_line function
- returns contents of the line + \n
- or NULL in case of error/nothing more to read
- usage: successively called until a NULL is returned

Q: what happens when buffer size covers two newlines


text:
"First line (10 chars)
Second Line (11 chars)
Third Line
Forth Line"

buffer_size = 24

on first read:
"First line 
Second Line 
Thi"

we keep the part up to and inc the first newline
"First line\n"

the remainder is kept within our static variable 'keep'
"Second Line 
Thi"

A static variable doesn’t lose its memory that easily. Its data persists until the end of the program, whether or not the function in which it was declared ends.

on second read:

our function should:

read n chars from our file
store them in KEEP
if '\n' found in KEEP:
	stop the loop
	split off everything up to and including /n and call this LINE
keep will just have what remains


get_line



## OLD NOTES
https://www.codequoi.com/en/42-get_next_line-project/

Reading in chunks

chunk		raw_line
"Test"		"Test"
" thi"		"Test thi"
"s\nfi"		"Test this\nfi"
- \n detected, exit returning 1
- print everything before \n
- send everything before n back in
"le"
- no_bytes < 4 detected, return 0 (EOF)

Write a function which returns a line read from a file descriptor, without the newline.

Files:
- get_next_line.c
- get_next_line_utils.c
- get_next_line.h

Prototype/Parameters:
int get_next_line(int fd, char **line);

Ext funcs:
read, malloc, free

Return value(s)
1 : A line has been read
0 : EOF has been reached
-1 : An error happened

BIG Q:
- will this approach still work when chunk size covers more than one nl?

OTHER NOTES:

https://en.wikipedia.org/wiki/Static_variable

static variable is a variable whose lifetime is the entire run of the program
static memory happens at compile time, not run time
can be modified
Q: how to know when a var should be static and when not?
Q: what are the static variables in our get_next_line?

// ssize_t read(int fildes, void *buf, size_t nbyte);
// Upon successful completion, these functions shall return a non-
//        negative integer indicating the number of bytes actually read.
//        Otherwise, the functions shall return -1 and set errno to
//        indicate the error.