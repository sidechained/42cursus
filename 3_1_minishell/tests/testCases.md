Minishell Test Cases
====================

For now, test cases will contain:
some of the commands: ' " | < > << >> $ $?
one builtin: echo
one executable with argument: wc -c
(pref more than one argument)

# Simple Test Cases

## Redirections

- format: `[n]>word`
where word is the expanded filename and n is the file descriptor
e.g. in `wc<infile`, wc redirects stdout file descriptor [0] to file given by infile
- `[n]<word`: 

### Input Redirection

`wc -c<infile`
`wc -c < infile`
`< infile wc -c`


### Output Redirection

`echo $PWD>outfile`
`echo $PWD > outfile`
`> outfile echo $PWD`

### Both Input and Output Redirection

`wc < infile > outfile`

## Pipes

`pwd|wc`
`pwd | wc`

## Single Quotes

### Within Command Argument

`echo 'bo||diddly'`

### Within Filename

`pwd > 'bo||diddly'`

## Double Quotes

### Within Command Argument

`echo "bo||diddly$SHLVL"``

### Within Filename

`pwd > "bo||diddly$SHLVL"`

## Compound Test Cases

`pwd|wc>outfile`
`pwd | wc > outfile`
`wc -c<infile > "out|file$?1"_test`
	
### Toward A Few Statements That Test for Everything

- a builtin and an executable
- input and output redirection
- all commands: ' " | < > << >> $ $?
- can have i/p redirection or builtin but NOT both (can't pipe to any of our builtins)
- also must test for both forms of infile/outfile (< preceding/following command)
- so therefore using these test statements:

`wc<infile > "out|file$?1"`
`<infile wc > "out|file$?1"``
`echo 'bo||diddly'$PWD | wc > "out|file$?2"`
`echo 'bo||diddly'$PWD | > "out|file$?2" wc`


