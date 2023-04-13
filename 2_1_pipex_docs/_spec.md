// understanding the flow and commands

- surely the second child process MUST wait for the result of the first child process
- it could be that we are printing within the process somehow, so debugging can be hard

pipe
- pipe command is given an array of 2 ints
- it returns two file descriptions which represent different ends of the pipe
- by default I'm guessing they are stdin and stdout
- good example: https://man7.org/linux/man-pages/man2/pipe.2.html

dup2
waitpid
close


// general program flow

pipe(p)

parent process

fork1

fork2

