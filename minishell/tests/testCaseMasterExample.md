EXAMPLE: `echo 'bo||diddly'$PWD trundlewheel | wc -c > "out|file$?2"`
=====================================================

# Identify and split off elements in single quotes

`echo `											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = NULL
`'bo||diddly'`									type = UNDETERMINED		in_single_quotes = true		in_double_quotes = NULL
`$PWD trundlewheel | wc -c > "out|file$?2"`		type = UNDETERMINED		in_single_quotes = false	in_double_quotes = NULL

# Identify and split off elements in double quotes

`echo `											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`'bo||diddly'`									type = UNDETERMINED		in_single_quotes = true		in_double_quotes = false
`$PWD trundlewheel | wc -c > `					type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`"out|file$?2"`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = true

# Split UNDETERMINED elements by redirection operators, labelling operators

`echo `											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`'bo||diddly'`									type = UNDETERMINED		in_single_quotes = true		in_double_quotes = false
`$PWD trundlewheel | wc -c `					type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`>`												type = OP_REDIR_OP		in_single_quotes = false	in_double_quotes = false
` `												type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`"out|file$?2"`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = true

# Split UNDETERMINED elements by pipe, labelling pipes

`echo `											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`'bo||diddly'`									type = UNDETERMINED		in_single_quotes = true		in_double_quotes = false
`$PWD trundlewheel `							type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`|`												type = PIPE_OP			in_single_quotes = false	in_double_quotes = false
` wc -c `										type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`>`												type = OP_REDIR_OP		in_single_quotes = false	in_double_quotes = false
` `												type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`"out|file$?2"`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = true

# Expand $'s anywhere but IN_SINGLE_QUOTES
			
`echo `											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`'bo||diddly'`									type = UNDETERMINED		in_single_quotes = true		in_double_quotes = false
`/minishell trundlewheel `						type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`|`												type = PIPE_OP			in_single_quotes = false	in_double_quotes = false
` wc -c `										type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`>`												type = OP_REDIR_OP		in_single_quotes = false	in_double_quotes = false
` `												type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`"out|file02"`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = true
			
# Remove whitespace from start and end of UNDETERMINED elements

`echo`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`'bo||diddly'`									type = UNDETERMINED		in_single_quotes = true		in_double_quotes = false
`/minishell trundlewheel`						type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`|`												type = PIPE_OP			in_single_quotes = false	in_double_quotes = false
`wc -c`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`>`												type = OP_REDIR_OP		in_single_quotes = false	in_double_quotes = false
												type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`"out|file02"`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = true

# Remove any UNDETERMINED elements that are empty

`echo`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`'bo||diddly'`									type = UNDETERMINED		in_single_quotes = true		in_double_quotes = false
`/minishell trundlewheel`						type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`|`												type = PIPE_OP			in_single_quotes = false	in_double_quotes = false
`wc -c`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`>`												type = OP_REDIR_OP		in_single_quotes = false	in_double_quotes = false
`"out|file02"`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = true

# Split UNDETERMINED elements by whitespace

`echo`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`'bo||diddly'`									type = UNDETERMINED		in_single_quotes = true		in_double_quotes = false
`/minishell`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`/trundlewheel`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`|`												type = PIPE_OP			in_single_quotes = false	in_double_quotes = false
`wc`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`-c`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`>`												type = OP_REDIR_OP		in_single_quotes = false	in_double_quotes = false
`"out|file02"`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = true

# Reclassify element following redirection operators, removing operator
- < << as INFILE
- > >> as OUTFILE

`echo`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`'bo||diddly'`									type = UNDETERMINED		in_single_quotes = true		in_double_quotes = false
`/minishell`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`/trundlewheel`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`|`												type = PIPE_OP			in_single_quotes = false	in_double_quotes = false
`wc`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`-c`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`"out|file02"`									type = OUTFILE			in_single_quotes = false	in_double_quotes = true

# Identify the first of a list of UNDETERMINED elements as a command

`echo`											type = COMMAND			in_single_quotes = false	in_double_quotes = false
`'bo||diddly'`									type = UNDETERMINED		in_single_quotes = true		in_double_quotes = false
`/minishell`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`/trundlewheel`									type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`|`												type = PIPE_OP			in_single_quotes = false	in_double_quotes = false
`wc`											type = COMMAND			in_single_quotes = false	in_double_quotes = false
`-c`											type = UNDETERMINED		in_single_quotes = false	in_double_quotes = false
`"out|file02"`									type = OUTFILE			in_single_quotes = false	in_double_quotes = true

# Identify UNDETERMINED elements following commands as ARGUMENT's

`echo`											type = COMMAND			in_single_quotes = false	in_double_quotes = false
`'bo||diddly'`									type = ARGUMENT			in_single_quotes = true		in_double_quotes = false
`/minishell`									type = ARGUMENT			in_single_quotes = false	in_double_quotes = false
`/trundlewheel`									type = ARGUMENT			in_single_quotes = false	in_double_quotes = false
`|`												type = PIPE_OP			in_single_quotes = false	in_double_quotes = false
`wc`											type = COMMAND			in_single_quotes = false	in_double_quotes = false
`-c`											type = ARGUMENT			in_single_quotes = false	in_double_quotes = false
`"out|file02"`									type = OUTFILE			in_single_quotes = false	in_double_quotes = true

# Parse commands from left to right

## locate first command 'echo':
### determine input:
- look for input redirection [INFILE directly before/after command + args] - none
- look for pipe directly before command - none
- [so input is STDIN]
### determine output:
- look for output redirection [OUTFILE directly before/after command + args] - none
- look for pipe directly after command + args - present
- [so output is pipe[1] and we must close pipe[0]]
### execute:
- echo is a BUILTIN_COMMAND, so to execute:
echo(in_fd, out_fd, `'bo||diddly'/minishell`, `trundlewheel`)

## locate next command 'wc'
### determine input:
- look for input redirection [INFILE directly before/after command + args] - none
- look for pipe directly before command - present
- [so input is pipe[0] and we must close pipe[1]]
### determine output:
- look for output redirection [OUTFILE directly before/after command + args] - present
- look for pipe directly after command + args - none
- [so output is to OUTFILE]
### execute:
- first, use dup2 to swap STDOUT for the file descriptor generated by opening OUTFILE
- wc is a EXECUTABLE_COMMAND, so to execute:
- call execve(const char *pathname, char *const argv[], char *const envp[]);
- passing arguments as argv[] and passing on envp[] grabbed in main

## when no more commands then done
