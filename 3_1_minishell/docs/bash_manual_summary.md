3.1.1 Minishell Operation

1. Read input from terminal
2. Break into tokens (words and operators), obeying quoting rules
- for single quotes: preserve the literal value of each character within the quotes. A single quote may not occur between single quotes
- for double quotes: preserve the literal value of all characters within the quotes, with the exception of ‘$’ and ‘`’
3. Parse tokens into simple commands
A simple command such as "echo a b c" is just a sequence of words separated by blanks, terminated by one of the shell’s control operators (& or ; in minishell). The first word generally specifies a command to be executed, with the rest of the words being that command’s arguments.

a. The words that the parser has marked as redirections are saved for later processing.
b. The words that are not redirections are expanded. Perform shell parameter expansions ($VARNAME and $?) breaking expanded tokens into lists of filenames and commands and arguments

If any words remain after expansion, the first word is taken to be the name of the command and the remaining words are the arguments.

c. Perform redirections (< << > >>) from left to right, removing redirection operands and operators from list
If no command name results, redirections are performed, but do not affect the current shell environment. A redirection error causes the command to exit with a non-zero status.

d.If there is a command name left after expansion, execution proceeds as described below. Otherwise, the command exits with a status of zero.

The shell scans the results of parameter expansion that did not occur within double quotes for word splitting. 
Any sequence of <space>, <tab>, and <newline> serves to delimit words, except at beginning and end where they are ignored. See word splitting section for extra rules. Note that if no expansion occurs, no splitting is performed.
4b. Quote removal. After the preceding expansions, all unquoted occurrences of the characters ‘'’, and ‘"’ that did not result from one of the above expansions are removed.

After a command has been split into words, if it results in a simple command and an optional list of arguments, execute the command as follows:
-If the command name contains no slashes, the shell attempts to locate it.  the shell searches for it in the list of shell builtins. If a match is found, that builtin is invoked.
-If the name is not a builtin, and contains no slashes, Bash searches each element of $PATH for a directory containing an executable file by that name.  If the search is unsuccessful, the shell prints an error message and returns an exit status of 127.
-If the search is successful, or if the command name contains one or more slashes, the shell executes the named program in a separate execution environment. Argument 0 is set to the name given, and the remaining arguments to the command are set to the arguments supplied, if any.
-If this execution fails because the file is not in executable format, and the file is not a directory, it is assumed to be a shell script and the shell executes it as described in Shell Scripts.
-If the command was not begun asynchronously, the shell waits for the command to complete and collects its exit status.

3.2 Shell Commands
3.2.3 Pipelines - when?
A sequence of one or more commands separated by ‘|’. The output of each command in the pipeline is connected via a pipe to the input of the next command. That is, each command reads the previous command’s output. This connection is performed before any redirections specified by the command.
Each command in a multi-command pipeline, where pipes are created, is executed in its own subshell, which is a separate process.
The exit status of a pipeline is the exit status of the last command in the pipeline.

3.2.4 Lists of Commands
A list is a sequence of one or more pipelines separated by ; and terminated by ; or a newline. Commands separated by ; are executed sequentially; the shell waits for each command to terminate in turn. The return status is the exit status of the last command executed.

3.4 Shell Parameters
**Note we are only implementing these within the context of looking them up in the environment i.e. no parameter assignment can be done (except via export, unset builtins).
**I.e. we are implementing variables but not parameters?!

A parameter is an entity that stores values. It can be a name, a number, or one of the special characters listed below. A variable is a parameter denoted by a name. A variable has a value. A parameter is set if it has been assigned a value. The null string is a valid value. Once a variable is set, it may be unset only by using the unset builtin command.

A variable may be assigned to by a statement of the form
name=[value] 

If value is not given, the variable is assigned the null string. All parameter and variable expansion and quote removal (see Shell Parameter Expansion).

3.4.2 Special Parameters
($?) Expands to the exit status of the most recently executed foreground pipeline.

3.5 Shell Expansions
Expansion is performed on the command line after it has been split into tokens. 
3.5.3 Shell Parameter Expansion
The ‘$’ character introduces parameter expansion. We are just implementing the basic form of '$EXAMPLE' not using the form surrounded by braces
The basic form of parameter expansion is ${parameter}. The value of parameter is substituted. The parameter is a shell parameter as described above (see Shell Parameters)

3.5.7 Word Splitting
Special rules
Explicit null arguments ("" or '') are retained and passed to commands as empty strings. Unquoted implicit null arguments, resulting from the expansion of parameters that have no values, are removed. If a parameter with no value is expanded within double quotes, a null argument results and is retained and passed to a command as an empty string. When a quoted null argument appears as part of a word whose expansion is non-null, the null argument is removed. That is, the word -d'' becomes -d after word splitting and null argument removal.

3.6 Redirections
Before a command is executed, its input and output may be redirected using a special notation interpreted by the shell. Redirections are processed in the order they appear, from left to right.

3.6.1 Redirecting Input
Redirection of input causes the file whose name results from the expansion of word to be opened for reading on file descriptor n, or the standard input (file descriptor 0) if n is not specified. The general format for redirecting input is: [n]<word

3.6.2 Redirecting Output
Redirection of output causes the file whose name results from the expansion of word to be opened for writing on file descriptor n, or the standard output (file descriptor 1) if n is not specified. If the file does not exist it is created; if it does exist it is truncated to zero size. The general format for redirecting output is: [n]>word

3.6.3 Appending Redirected Output
Redirection of output in this fashion causes the file whose name results from the expansion of word to be opened for appending on file descriptor n, or the standard output (file descriptor 1) if n is not specified. If the file does not exist it is created. The general format for appending output is:
[n]>>word

3.6.6 Here Documents
This type of redirection instructs the shell to read input from the current source until a line containing only word (with no trailing blanks) is seen. All of the lines read up to that point are then used as the standard input (or file descriptor n if n is specified) for a command.

The format of here-documents is:
[n]<<[-]word here-document delimiter 

If any part of word is quoted, the delimiter is the result of quote removal on word, and the lines in the here-document are not expanded. If word is unquoted, all lines of the here-document are subjected to parameter expansion, command substitution, and arithmetic expansion, the character sequence \newline is ignored, and ‘\’ must be used to quote the characters ‘\’, ‘$’, and ‘`’.

3.7 Executing Commands
Exit Status
Signals

3.7.1 Simple Command Expansion


3.7.2 Command Search and Execution


3.7.4 Environment
When a program is invoked it is given an array of strings called the environment. This is a list of name-value pairs, of the form name=value.

On invocation, the shell scans its own environment and creates a parameter for each name found, automatically marking it for export to child processes. Executed commands inherit the environment. The export and unset commands allows parameters and functions to be added to and deleted from the environment. 

3.7.5 Exit Status
The exit status of an executed command is the value returned by the waitpid system call or equivalent function. For the shell’s purposes, a command which exits with a zero exit status has succeeded. A non-zero exit status indicates failure.

If a command is not found, the child process created to execute it returns a status of 127. If a command is found but is not executable, the return status is 126.

If a command fails because of an error during expansion or redirection, the exit status is greater than zero.

The exit status of the last command is available in the special parameter $?

3.7.6 Signals
Look at this section again when


4 Shell Builtin Commands
Builtin commands are contained within the shell itself. When the name of a builtin command is used as the first word of a simple command (see Simple Commands), the shell executes the command directly, without invoking another program.

4.1 Bourne Shell Builtins
cd [directory] 
Change the current working directory to directory.

Relative paths:
If the directory does not begin with a slash and the shell variable CDPATH exists, it is used as a search path: each directory name in CDPATH is searched for directory, with alternative directory names in CDPATH separated by a colon (‘:’). 
Absolute paths:
If directory begins with a slash, CDPATH is not used.

If a non-empty directory name from CDPATH is used, or if ‘-’ is the first argument, and the directory change is successful, the absolute pathname of the new working directory is written to the standard output.

If the directory change is successful, cd sets the value of the PWD environment variable to the new directory name, and sets the OLDPWD environment variable to the value of the current working directory before the change.

The return status is zero if the directory is successfully changed, non-zero otherwise.

exit [n] 
Exit the shell with the exit status of the last command executed. Any trap on EXIT is executed before the shell terminates

export [name[=value]] 
- am I allowing setting of value here?
Mark each name to be passed to child processes in the environment. The names refer to shell variables. If no names are supplied, a list of names of all exported variables is displayed. If a variable name is followed by =value, the value of the variable is set to value.

The return status is zero unless an invalid option is supplied, one of the names is not a valid shell variable name, or -f is supplied with a name that is not a shell function.

pwd
Print the absolute pathname of the current working directory.

unset [name] 
Remove each variable. If no options are supplied, each name refers to a variable; if there is no variable by that name, a function with that name, if any, is unset. Readonly variables and functions may not be unset. Some shell variables lose their special behavior if they are unset; such behavior is noted in the description of the individual variables. The return status is zero unless a name is readonly or may not be unset

4.2 Bash Builtin Commands
echo [arg …] 
Output the args, separated by spaces, terminated with a newline. The return status is 0 unless a write error occurs

5.1 Bourne Shell Variables
CDPATH 
A colon-separated list of directories used as a search path for the cd builtin command.

PATH
A colon-separated list of directories in which the shell looks for commands. A zero-length (null) directory name in the value of PATH indicates the current directory. A null directory name may appear as two adjacent colons, or as an initial or trailing colon.

6.3 Interactive Shells
An interactive shell generally reads from and writes to a user’s terminal
We are using an interactive shell
Can test with isatty(3)

6.3.3 Interactive Shell Behavior

When the shell is running interactively, it changes its behavior in several ways.

Job Control (see Job Control) is enabled by default. When job control is in effect, Bash ignores the keyboard-generated job control signals SIGTTIN, SIGTTOU, and SIGTSTP.

Readline (see Command Line Editing) is used to read commands from the user’s terminal.

Command history (see Bash History Facilities) and history expansion (see History Expansion) are enabled by default. Bash will save the command history to the file named by $HISTFILE when a shell with history enabled exits.

Alias expansion (see Aliases) is performed by default.

In the absence of any traps, Bash ignores SIGTERM (see Signals).

In the absence of any traps, SIGINT is caught and handled (see Signals). SIGINT will interrupt some shell builtins..

8 Command Line Editing
**I didn't summarise this section deeply as we will just implement readline 'as is'
This chapter describes the basic features of the GNU command line editing interface. Command line editing is provided by the Readline library, which is used by several different programs, including Bash. 

9 Using History Interactively
** Didn't go into this deeply, as we will just use a basic default form of history keeping
9.1 Bash History Facilities
When the -o history option to the set builtin is enabled (see The Set Builtin), the shell provides access to the command history, the list of commands previously typed.