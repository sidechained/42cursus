# resources

https://github.com/twagger/minishell
https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html

# requirements

Your shell should:
v Display a prompt when waiting for a new command.
v Have a working history.
v Search and launch the right executable (based on the PATH variable or using a relative or an absolute path).
v Not use more than one global variable. Think about it. You will have to explain its purpose.
• Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon).
• Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
• Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
• Implement redirections:
        ◦ < should redirect input.
        ◦ > should redirect output.
        ◦ << should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
        ◦ >> should redirect output in append mode.
• Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
• Handle environment variables ($ followed by a sequence of characters) which should expand to their values.
• Handle $? which should expand to the exit status of the most recently executed foreground pipeline.
v Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
• In interactive mode:
        v ctrl-C displays a new prompt on a new line.
        v ctrl-D exits the shell.
        v ctrl-\ does nothing.
v Your shell must implement the following builtins:
        ◦ echo with option -n
        ◦ cd with only a relative or absolute path
        ◦ pwd with no options
        ◦ export with no options
        ◦ unset with no options
        ◦ env with no options or arguments
        ◦ exit with no options
The readline() function can cause memory leaks. You don’t have to fix them. But that doesn’t mean your own code, yes the code you wrote, can have memory leaks.

# shell syntax

reads its input from a file (see sh)
breaks the input into tokens: words and operators; see Token Recognition.
parses the input into simple commands (see Simple Commands) and compound commands (see Compound Commands).
performs various expansions (separately) on different parts of each command, resulting in a list of pathnames and fields to be treated as a command and arguments; see Word Expansions.
performs redirection (see Redirection) and removes redirection operators and their operands from the parameter list.
executes a function (see Function Definition Command), built-in (see Special Built-In Utilities), executable file, or script, giving the names of the arguments as positional parameters numbered 1 to n, and the name of the command (or in the case of a function within a script, the name of the script) as the positional parameter numbered 0 (see Command Search and Execution).
optionally waits for the command to complete and collects the exit status (see Exit Status for Commands).

# global variable

For this project we could use one global variable. At first it seemed we were never going to need one, but later it became obvious that it is required. Specifically, it has to do with signals. When you use signal to capture SIGINT (from Ctrl-C) and SIGQUIT (from Ctrl-\) signals, we have to change the error status, and the signal function has no obvious way of retrieving the updated exit status that shoud change when either of these signals are captured. To work this around, we added a global variable g_status that updates the error status when signals are detected.