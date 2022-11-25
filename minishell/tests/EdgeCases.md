Edge Cases
==========

A list of things to put in test cases that might fuck up the system:

Q: what happens when a quote has a space in it?

Q: what happens when a command not in first position has input redirection? e.g.
`echo bobblefax | wc -c < infile`
A: it executes the command on both inputs resulting in `39` whereas `echo bobblefax | wc -c` gives `10` and `wc -c < infile` gives `29`. But how can we handle this?!

Q: what happens when a command not in last position has output redirection?
Q: what happens if we have both redirection and a pipe?!
`echo bobble > out_bob | wc > out_wc`
- it is possible to both output to a file AND pass the result to another command with a pipe
- output redirection does NOT have to be the last command
- 

Q: what happens when a command has multiple args i.e. echo fuck you totally
A: they appear as output! so handle this!

Q: What happens if another element follows and in/out file i.e. `wc -c<infile twing > "out|file$?1"_test`