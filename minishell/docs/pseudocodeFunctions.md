Minishell Pseudocode Functions
==============================

# use consts where possible

STDIN_FD 0
STDOUT_FD 1

UNDEFINED 0
BUILTIN_CMD 1
CMD_ARG 2
PIPE_OP 3
EXEC_CMD 4
CMD_ARG 5
OUTFILE 6

// Example Data Structure

["echo", "test", "|", "wc", "-c", "outfile"]
[BUILTIN_CMD, CMD_ARG, PIPE_OP, EXEC_CMD, CMD_ARG, OUTFILE]

int main(int argc, char** argv, char** env)
{
	char* statement;
	statement = "echo \'bo||diddly\'$PWD trundlewheel | wc > \"out|file$?2\"";
	return(0);
}

isInQuotes()
{
	// return true if a character is within quotes else return false
}

split_by_redirection_operators()
{
	// arrayOfOperators = ["<", ">" "<<", ">>"];
	// operator = "<"

	// how to split by double characters?

	// find < in

	// ft_split won't cut it, because we have to split by two subsequent characters

}

split_by_pipe()
{
	// |
	// for this I can use ft_split
}

perform_dollar_expansions()
{
	// $ and $?
}

parse_commands()
{
	//
}

detect_builtins()
{
	if (command == "echo")
	{
		builtin_echo();
	}
	else
	{
		execute_command();
	}
}

builtin_echo(int in_fd, int out_fd, char* args[])
{

}

execute_command(char* command, char* args[], char* env)
{

}

trim_whitespace()
{
	ft_strtrim(stringToTrim, " \t")	
}

## Library Functions

// ft_strtrim - Allocates and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.

// ft_split - Allocates and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer.