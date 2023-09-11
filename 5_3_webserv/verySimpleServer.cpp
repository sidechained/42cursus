// c++ -Wall -Werror -Wextra -std=c++98 verySimpleServer.cpp && ./a.out

// THE PROCESS:
// 1. open a socket() representing the server
// 2. bind() the socket to an address and port (e.g. 127.0.0.1:8080)
// 3. listen() for incoming connections on the socket
// 4. when a connection is received
// - accept() it, getting the client address in the process 
// - recv() it on the client address, storing the result in a buffer
// - TODO: parse the request and...
// - send() an OK response, first the header then the body (a html file)
// NOTE: the connect() method is typically used on the client side, so we won't use it here

// TODO:
// - parse correct GET request before sending response
// - DONE: CTRL+D should stop server
// - DONE: html response should be sent from file

// INFO:
// - to unblock a port: 
// get pid: sudo lsof -i :<port number>
// kill pid: sudo kill -9 <PID>

// MACRO meanings:
// AF_INET is address family for IPv4
// SOCK_STREAM specifies TCP
// IPPROTO_TCP
// INADDR_ANY = listen on all available network interfaces
// INADDR_LOOPBACK = listen only on localhost

#include <arpa/inet.h>  // For sockaddr_in, htons
#include <string.h> // memset - eventually will be replaced
#include <iostream>
//#include <sys/socket.h> // socket, bind, listen
#include <unistd.h> // close
#include <fcntl.h>
#include <errno.h>
#include <fstream> // ifstream
#include <sstream>

#define OK_RESPONSE_BODY_FILENAME "/responses/OKResponse.html"
#define MAX_CONNECTIONS 5
#define SERVER_PORT 8890

// Convert an integer to a string using stringstream
std::string intToString(int value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

int send_ok_response_header(int client_sockfd, std::ifstream &htmlFile)
{
    htmlFile.seekg(0, std::ios::end);
    int contentLength = htmlFile.tellg();
    htmlFile.seekg(0, std::ios::beg);

    std::string responseHeaders = "HTTP/1.1 200 OK\r\n";
    responseHeaders += "Content-Type: text/html\r\n";
    responseHeaders += "Content-Length: " + intToString(contentLength) + "\r\n";
    responseHeaders += "\r\n"; // End of headers
    ssize_t bytes_sent = send(client_sockfd, responseHeaders.c_str(), responseHeaders.length(), 0);
    if (bytes_sent == -1)
    {
        std::cerr << "Error sending HTTP response headers" << std::endl;
        htmlFile.close();
        return 1;
    }
    return 0;
}

int send_ok_response_body(int client_sockfd, std::ifstream &htmlFile)
{
    char buffer[1024];
    while (!htmlFile.eof())
    {
        htmlFile.read(buffer, sizeof(buffer));
        ssize_t bytes_read = htmlFile.gcount();
        if (bytes_read > 0)
        {
            ssize_t bytes_sent = send(client_sockfd, buffer, bytes_read, 0);
            if (bytes_sent == -1) {
                std::cerr << "Error sending file contents" << std::endl;
                htmlFile.close();
                return 1;
            }
        }
    }
    return 0;
}

void send_ok_response(int client_sockfd)
{
    std::ifstream htmlFile(OK_RESPONSE_BODY_FILENAME, std::ios::binary);
    if (!htmlFile) {
        std::cerr << "Error opening HTML file" << std::endl;
        return ;
    }
    if (send_ok_response_header(client_sockfd, htmlFile))
    	return ;
    if (send_ok_response_body(client_sockfd, htmlFile))
    	return ;
    htmlFile.close();
    std::cout << "HTTP response headers and file sent successfully" << std::endl;
}

int create_socket(int &sockfd)
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		std::cerr << "Error creating socket" << std::endl;
		return 1;
	}
	std::cout << "Socket created successfully" << std::endl;
	return 0;
}

// bind to specific address and port
int bind_socket(int &sockfd, int serverPort)
{
	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(serverPort);
	server_address.sin_addr.s_addr = INADDR_ANY; // Listen on all available network interfaces
	if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
	{
	    std::cerr << "Error binding to socket" << std::endl;
	    close(sockfd);
	    return 1;
	}
	std::cout << "Socket bound to address successfully" << std::endl;
	return 0;
}

void print_request(char (&buffer)[1024], int &bytesRead)
{
	std::cerr << "Received the following data from client..." << std::endl;
	std::cout.write(buffer, bytesRead);
	std::cout << std::endl;
}

void accept_connection(int &client_sockfd)
{
	std::cout << "Accepted a connection" << std::endl;
	// Handle the client connection here
	char buffer[1024];
	int bytesRead = recv(client_sockfd, buffer, sizeof(buffer), 0);
	if (bytesRead > 0)
	{
		print_request(buffer, bytesRead);
		send_ok_response(client_sockfd);
	}
	else if (bytesRead == 0)
	{
		std::cerr << "Error, Connection closed by client" << std::endl;
	}
	else if (errno == EAGAIN || errno == EWOULDBLOCK)
	{
		std::cerr << "Error, No data available to read" << std::endl;
	}
	else
	{
		std::cerr << "Error receiving data" << std::endl;
	}
	// Close the client socket when done
	std::cerr << "Closing client socket..." << std::endl;
	close(client_sockfd);
}

int listen_for_connections(int &sockfd)
{
	if (listen(sockfd, MAX_CONNECTIONS) == -1) { // Maximum 5 pending connections
	    std::cerr << "Error listening on socket" << std::endl;
	    close(sockfd);
	    return 1;
	}
	std::cout << "Waiting for connections... (Press CTRL+D to exit)" << std::endl;
	char input;
	while (std::cin >> input)
	{
		struct sockaddr_in client_address;
		socklen_t client_addr_len = sizeof(client_address);
		int client_sockfd = accept(sockfd, (struct sockaddr*)&client_address, &client_addr_len);

		if (client_sockfd < 0)
		{
		    if (errno == EAGAIN || errno == EWOULDBLOCK)
		    {
		        // No connection pending, handle accordingly
		        // You can use this time to perform other tasks
		    }
		    else
		    {
		        std::cerr << "Error accepting connection" << std::endl;
		    }
		}
		else
		{
			accept_connection(client_sockfd);
       	}
       	if (std::cin.eof())
       	{
       		std::cout << "EOF (CTRL+D) detected. Exiting the loop." << std::endl;
    	}
    	else
    	{
        	std::cout << "Input error or other termination condition." << std::endl;
    	}
    }	
	return 0;
}

int main()
{
	int sockfd;
	if (create_socket(sockfd))
		return 1;
	if (bind_socket(sockfd, SERVER_PORT))
		return 1;
	if (listen_for_connections(sockfd))
		return 1;
	close(sockfd);
	std::cout << "Server socket closed" << std::endl;
	return 0;
}