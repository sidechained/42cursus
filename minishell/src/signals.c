// https://medium.com/@aantipov/what-happens-when-you-ctrl-c-in-the-terminal-36b093443e06
// https://linuxhint.com/signal_handlers_c_programming_language/
// https://www.gnu.org/software/bash/manual/bash.html#Signals

// ctrl-C / sends SIGINT interrupt
// received by the current foreground process which terminates itself, returning to command prompt
// print a new prompt on a newline

// ctrl-D
// exit the shell (only works at the beginning of a line)
// https://stackoverflow.com/questions/1516122/how-to-capture-controld-signal
// The ctrl-d or ^D is the default value for eof and is a special internal control character for the terminal session and is an exit provided by the terminal driver in the shell kernel. In more technical terms the c_cc of the termios structure passed to the TCSETS/TCGETS ioctl is affected by the use of the CTRL-D and is forced to exit.

// To see all of the parameters do a stty -a from the shell, the eof one shown is the one used with the CTRL-D

// ctrl-\ do nothing. / normally SIGQUIT
// CTRL-\ is the Linux key that generates the QUIT signal. Generally, that signal causes a program to terminate and dump core. If you want to disable that feature, use the stty command.
// stty -a shows hotkeys, as follows:
// intr = ^C - CHAR will send an interrupt signal i.e SIGINT
// eof = ^D - CHAR will send an end of file (terminate the input) i.e.
// quit = ^\ - CHAR will send a quit signal
// man stty has more info
// man kill has more info

// Signal: A signal is an event which is generated to notify a process or thread that some important situation has arrived. When a process or thread has received a signal, the process or thread will stop what its doing and take some action. Signal may be useful for inter-process communication.

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
#include <signal.h>
#include <stdbool.h>

static volatile int keepRunning = true; // this is the mentioned global variable!

void sig_handler(int signo)
{
	switch(signo)
	{
		case SIGINT:
    		keepRunning = false;
    		break;
	}
	
}

int main(void)
{
	struct sigaction act;
	act.sa_handler = sig_handler;
 	sigaction(SIGINT, &act, NULL);
	while(keepRunning) 
	{
		readline("test > ");
	}
	return 0;
}