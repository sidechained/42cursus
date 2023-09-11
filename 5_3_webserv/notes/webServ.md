WebServ FAQ/Specification

# Glossary

## .ipp file

The ".ipp" file format in C++ typically represents an "Inline Template" file, which contains template function definitions defined inline within a header file to facilitate code reuse and optimization.

## Sockets

A socket is an endpoint for network communication, allowing data transmission between processes or applications over a computer network, typically identified by an IP address and port number.

Sockets are represented by file descriptors (integer values) in Unix-like operating systems. When you create a socket, the operating system assigns it a file descriptor, just like it does for regular files. You can use this file descriptor to read from or write to the socket.

## Info

# Which external functions do we need and for what?

execve         - Execute a program with a specified filename.
dup            - Duplicate an open file descriptor.
dup2           - Duplicate an open file descriptor to a specific number.
pipe           - Create a pipe for interprocess communication.
fork           - Create a new process by duplicating the current process.


strerror       - Retrieve a string describing an error code.
gai_strerror   - Retrieve a string describing a getaddrinfo error code.
errno          - Global variable storing the last error code.


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

sockets:

socket         - Create a socket for network communication.
socketpair     - Create a pair of connected sockets.
accept         - Accept an incoming connection on a socket.
listen         - Set a socket to listen for incoming connections.
send           - Send data on a socket.
recv           - Receive data from a socket.
bind           - Bind a socket to a specific address and port.
connect        - Connect a socket to a remote server.
getaddrinfo    - Resolve hostnames and service names to socket addresses.
freeaddrinfo   - Free memory allocated by getaddrinfo.
setsockopt     - Set socket options.
getsockname    - Retrieve the local address of a socket.

getprotobyname - Retrieve protocol information by name.

file descriptors:
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

## How is poll() used?

Poll() is used to efficiently manage and multiplex multiple client connections without blocking the server's main thread.

The first argument to the poll() function is an array of struct pollfd structures.

Each struct pollfd structure represents a file descriptor (e.g., a socket) that you want to monitor for events.

The main data elements of pollfd are:

- fd: This member is an integer that represents the file descriptor you want to monitor. It's the file descriptor of the socket or file you want to check for events.
- events: This member is an integer bit mask that specifies the events you want to monitor for on the file descriptor. Common event flags include:
	- POLLIN: Indicates that you want to monitor for data available for reading (e.g., incoming data on a socket).
	- POLLOUT: Indicates that you want to monitor for the ability to write data (e.g., the socket's send buffer is not full).

## FAQ

# What are the differences and any advantages/disadvantages of using ? (as we can use any)




# What are examples of some basic Telnet/NGINX server tests we could try? What NGINX server could we actually try?

NGINX server may be used to compare headers and answer behaviors.

1. **Establishing a Connection:** You can use Telnet to establish a connection to the NGINX server on a specific port (usually port 80 for HTTP) to ensure that the server is responsive. Replace `your-server.com` with the actual server's domain name or IP address:

   ```
   telnet your-server.com 80
   ```

   If the connection is successful, you'll see a message like "Connected to your-server.com" indicating that the server is responsive.

2. **Sending an HTTP GET Request:** You can manually craft and send an HTTP GET request to retrieve a web page. After establishing the connection, type the following and press Enter twice:

   ```
   GET / HTTP/1.1
   Host: your-server.com
   ```

   Replace `your-server.com` with the appropriate domain or IP address. The server should respond with the HTTP headers and content of the default web page or the page associated with the root path ("/").

3. **Checking Headers:** You can check the HTTP response headers sent by the server. After sending the GET request, the server will respond with headers followed by content. Examine the headers to see information about the response. For example:

   ```
   HTTP/1.1 200 OK
   Server: nginx
   Date: Sat, 03 Sep 2023 12:34:56 GMT
   Content-Type: text/html
   Content-Length: 1234
   ```

   This example response header indicates a successful response with a "200 OK" status code and provides information about the server software, date, content type, and content length.

4. **Checking for Redirection:** If you want to test how NGINX handles redirects, you can use Telnet to check the response headers when requesting a resource that should trigger a redirection. For example:

   ```
   GET /redirected-page HTTP/1.1
   Host: your-server.com
   ```

   Observe the HTTP response headers to check for a "302 Found" status code and the "Location" header indicating the new location to which the client should be redirected.

These basic Telnet tests can help you verify the responsiveness of your NGINX web server and examine the HTTP headers and content it serves. Keep in mind that for more comprehensive testing and automation, dedicated web testing tools and frameworks are typically used.

# What are the relevant RFC's/headers we should try to implement?

Short answer: implement the headers you need to make the server work with the browser of your choice. A good starting point are RFC's 7230-7235 that were previously required by the assignment. These provide an updated specification for HTTP/1.1, focusing on message syntax and routing and supercede RFC 2616.

Other RFC's define standards other which may be useful to follow i.e.
- RFC2034 MIME structure and encoding
- RFC9110 NTS time protocol
- RFC9112 URI syntax for web addresses

From this we can cherry-pick which headers to use from the list below. The ones marked with a * are most important to implement to ensure a basic working web server with Chrome and most modern web browsers:

Accept-Charsets: Request header specifying accepted character encodings.
Accept-Language: Request header specifying accepted languages.
Allow: Response header indicating allowed HTTP methods.
Authorization: Request header containing user credentials.
Connection (*) : Specify "keep-alive" to keep open for multiple requests (performance), or "close".
Content-Language: Response header specifying content language.
Content-Length (*): Response header indicating length (in bytes) of the content
Content-Location: Response header with the location of the resource.
Content-Type (*): Response header specifying media/MIME type i.e. "text/html" "image/jpeg"
Date (*): Response header indicating the date and time (debugging).
Host: Request header specifying the target server.
Last-Modified: Response header indicating resource modification time.
Location: Response header for redirection target.
Referer: Request header showing the source of the request.
Retry-After: Response header indicating when to retry.
Server (*): Response header identifying the server software.
Transfer-Encoding: Response header specifying content encoding.
User-Agent: Request header indicating client software.
WWW-Authenticate: Response header for server authentication.



# Requirements

## What does it mean that a server should never block and the client be bounced?

It should efficiently handle multiple simultaneous requests without becoming unresponsive or delaying responses for other requests.
It achieves this by using non-blocking I/O operations and asynchronous processing, ensuring that one request doesn't prevent others from being processed.
"Bouncing" the client typically means that the server should not abruptly terminate or reject a client's request without handling it properly. Instead, the server should respond to the client, even if it cannot immediately fulfill the request.

# How do we use poll()?

Use only 1 poll() for all I/O operations between the client and the server (listen included).

• poll() must check read and write at the same time (POLLIN | POLLOUT)

# You can use every macro and define like FD_SET, FD_CLR, FD_ISSET, FD_ZERO (understanding what and how they do it is very useful).

macros used with fd_set data structure in socket programming, primarily for managing multiple file descriptors

FD_SET(fd, set): Adds a file descriptor fd to the fd_set referred to by set. It marks the file descriptor as one of the descriptors to be monitored for events.
FD_CLR(fd, set): Removes a file descriptor fd from the fd_set referred to by set. It unmarks the file descriptor, indicating that it should not be monitored for events.
FD_ISSET(fd, set): Checks if a file descriptor fd is part of the fd_set referred to by set. It returns true (non-zero) if the file descriptor is set, indicating that it has experienced an event; otherwise, it returns false (zero).
FD_ZERO(set): Initializes an fd_set referred to by set by clearing all file descriptors. It effectively sets all file descriptors in the set to be unmonitored.

commonly used when implementing event-driven programming with sockets to manage and monitor multiple sockets efficiently

# You can’t use fork for something else than CGI (like PHP, or Python, and so forth).

# Q: What do GET, POST, and DELETE methods do? (bare minimum needed)

A: 
GET: The GET method is used to request data from a specified resource, typically retrieving information from the server without altering it.
POST: The POST method is used to submit data to be processed to a specified resource, often used for sending form data to a server for further processing.
DELETE: The DELETE method is used to request the removal of a specified resource or data on the server.

# How to listen on multiple ports?

---


## What is CGI?

CGI (Common Gateway Interface) is a protocol that enables web servers to execute external programs or scripts, typically written in languages like Perl or Python, to generate dynamic web content in response to client requests.

∗ Because you won’t call the CGI directly, use the full path as PATH_INFO.
∗ Just remember that, for chunked request, your server needs to unchunk it, the CGI will expect EOF as end of the body.
∗ Same things for the output of the CGI. If no content_length is returned from the CGI, EOF will mark the end of the returned data.
∗ Your program should call the CGI with the file requested as first argument.
∗ The CGI should be run in the correct directory for relative path file access.
∗ Your server should work with one CGI (php-CGI, Python, and so forth).
You must provide some configuration files and default basic files to test and demonstrate every feature works during evaluation.
Do not test with only one program. Write your tests with a more convenient language such as Python or Golang, and so forth. Even in C or C++ if you want to.



# Link to Eval Sheet

https://rphlr.github.io/42-Evals/Rank05/webserv/
