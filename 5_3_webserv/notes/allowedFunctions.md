FORNOW:

poll           - Wait for events on multiple file descriptors with a timeout.

getaddrinfo    - Resolve hostnames and service names to socket addresses.
freeaddrinfo   - Free memory allocated by getaddrinfo.
setsockopt     - Set socket options.
getsockname    - Retrieve the local address of a socket.
getprotobyname - Retrieve protocol information by name.

ALL

execve         - Execute a program with a specified filename.
dup            - Duplicate an open file descriptor.
dup2           - Duplicate an open file descriptor to a specific number.
pipe           - Create a pipe for interprocess communication.
strerror       - Retrieve a string describing an error code.
gai_strerror   - Retrieve a string describing a getaddrinfo error code.
errno          - Global variable storing the last error code.
fork           - Create a new process by duplicating the current process.
socketpair     - Create a pair of connected sockets.
htons          - Convert a 16-bit integer to network byte order.
htonl          - Convert a 32-bit integer to network byte order.
ntohs          - Convert a 16-bit integer from network byte order.
ntohl          - Convert a 32-bit integer from network byte order.
select         - Wait for events on multiple file descriptors.
poll           - Wait for events on multiple file descriptors with a timeout.
epoll_create   - Create an epoll instance for I/O event monitoring.
epoll_ctl      - Control epoll events for a file descriptor.
epoll_wait     - Wait for events on file descriptors using epoll.
kqueue         - A BSD system call for event notification.
kevent         - Register and wait for events with kqueue.
socket         - Create a socket for network communication.
accept         - Accept an incoming connection on a socket.
listen         - Set a socket to listen for incoming connections.
send           - Send data on a socket.
recv           - Receive data from a socket.
chdir          - Change the current working directory.
bind           - Bind a socket to a specific address and port.
connect        - Connect a socket to a remote server.
getaddrinfo    - Resolve hostnames and service names to socket addresses.
freeaddrinfo   - Free memory allocated by getaddrinfo.
setsockopt     - Set socket options.
getsockname    - Retrieve the local address of a socket.
getprotobyname - Retrieve protocol information by name.
fcntl          - Perform various operations on file descriptors.
close          - Close an open file descriptor.
read           - Read data from a file descriptor.
write          - Write data to a file descriptor.
waitpid        - Wait for a child process to terminate.
kill           - Send a signal to a process.
signal         - Set a signal handler for a specific signal.
access         - Check file access permissions.
stat           - Get file status information.
opendir        - Open a directory for reading.
readdir        - Read a directory entry.
closedir       - Close a directory stream.