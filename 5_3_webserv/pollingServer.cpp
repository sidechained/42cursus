// polling, non-blocking webserver

// THE PROCESS / INSTRUCTIONS
// compile and run: c++ -Wall -Werror -Wextra -std=c++98 pollingServer.cpp && ./a.out
// in separate terminals, run the following command to send a GET request to the server
// $ // 

// - supports only GET requests
// - the DELETE request is only provided as an example of a bad request
// - httpVersion must be 1.1 otherwise it is considered a bad request

// TODO:
// - TODO: fix CTRL+D exit loop
// - TODO: poll must check read and write at the same time - what does it mean to check write? this is when we send response back to clients
// - DONE: basic parsing of GET requests
// - DONE: implemented OK and BAD responses
// - TODO: make into a class
// - TODO: develop main that reads from config file and instatiates objects from class
// - Q: is it non-blocking?

// Readability Check (POLLIN): When you specify the POLLIN flag for a file descriptor, you are checking if there is data available for reading from that descriptor. If poll() returns a positive value for a file descriptor with POLLIN set, it means you can safely read data from that descriptor without blocking.

// Writability Check (POLLOUT): When you specify the POLLOUT flag for a file descriptor, you are checking if you can write data to that descriptor without blocking. If poll() returns a positive value for a file descriptor with POLLOUT set, it means you can write data to that descriptor without it being full.

#include <arpa/inet.h> // For sockaddr_in, htons
// #include <netinet/in.h>
// #include <sys/socket.h>
#include <cstdlib> // EXIT_FAILURE etc
#include <poll.h>
#include <unistd.h> // close
#include <iostream> // cout, cin
#include <sstream> // stringstream
#include <fstream> // ifstream
#include <string.h> // memset - eventually will be replaced
#include <string>
#include <vector>

#define MAX_CLIENTS 2
#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 8081
#define OK_RESPONSE_BODY_FILENAME "responses/OKResponse.html"
#define BAD_REQUEST_RESPONSE_BODY_FILENAME "responses/BadRequestResponse.html"

struct HttpRequest {
    std::string method;
    std::string resource;
    std::string httpVersion;
    std::string host;
    std::string userAgent;
    std::string accept;
    std::string connection;
};

std::string intToString(int value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

bool parse_request(const std::string& request_str, HttpRequest& request) {
    std::istringstream requestStream(request_str);
    requestStream >> request.method >> request.resource >> request.httpVersion; // first line
    if (request.method == "GET" && request.httpVersion == "HTTP/1.1")
    {
        std::string headerName, headerValue;
        std::getline(requestStream, headerValue, '\n'); // skip newline
        while (std::getline(requestStream, headerName, ':') && std::getline(requestStream >> std::ws, headerValue)) {
            if (headerName == "Host") {
                request.host = headerValue;
            } else if (headerName == "User-Agent") {
                request.userAgent = headerValue;
            } else if (headerName == "Accept") {
                request.accept = headerValue;
            } else if (headerName == "Connection") {
                request.connection = headerValue;
            }
        }
        return true;
    }
    return false;
}

void print_request(HttpRequest& parsedRequest)
{
    std::cout << "Method: " << parsedRequest.method << std::endl;
    std::cout << "Resource: " << parsedRequest.resource << std::endl;
    std::cout << "HTTP Version: " << parsedRequest.httpVersion << std::endl;
    std::cout << "Host: " << parsedRequest.host << std::endl;
    std::cout << "User-Agent: " << parsedRequest.userAgent << std::endl;
    std::cout << "Accept: " << parsedRequest.accept << std::endl;
    std::cout << "Connection: " << parsedRequest.connection << std::endl;
}

void print_raw_request(char (&buffer)[1024], int &bytesRead)
{
	std::cerr << "Received the following data from client..." << std::endl;
	std::cout.write(buffer, bytesRead);
	std::cout << std::endl;
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

int send_response_body(int client_sockfd, std::ifstream &htmlFile)
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
    if (send_response_body(client_sockfd, htmlFile))
    	return ;
    htmlFile.close();
    std::cout << "HTTP response headers and file sent successfully" << std::endl;
}

int send_bad_request_response_header(int client_sockfd, std::ifstream &htmlFile)
{
    htmlFile.seekg(0, std::ios::end);
    int contentLength = htmlFile.tellg();
    htmlFile.seekg(0, std::ios::beg);

    std::string responseHeaders = "HTTP/1.1 400 Bad Request\r\n";
    responseHeaders += "Content-Type: text/html\r\n";
    responseHeaders += "Content-Length: " + intToString(contentLength) + "\r\n";
    responseHeaders += "Connection: close\r\n";
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

void send_bad_request_response(int client_sockfd)
{
    std::ifstream htmlFile(BAD_REQUEST_RESPONSE_BODY_FILENAME, std::ios::binary);
    if (!htmlFile) {
        std::cerr << "Error opening HTML file" << std::endl;
        return ;
    }
    if (send_bad_request_response_header(client_sockfd, htmlFile))
    	return ;
    if (send_response_body(client_sockfd, htmlFile))
    	return ;
    htmlFile.close();
    std::cout << "HTTP response headers and file sent successfully" << std::endl;
}

void init_server(int &serverSocket) {
    struct sockaddr_in serverAddr;
    // Create a server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error creating server socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the specified address and port
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error binding server socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 10) == 0) {
        std::cout << "Listening... (CTRL+D to exit)" << std::endl;
    } else {
        std::cerr << "Error listening on server socket" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void handle_client_connections(struct pollfd (&fdArray)[MAX_CLIENTS + 1], int &serverSocket, int &clientCount) {
    struct sockaddr_in newAddr;
    socklen_t addrSize;

    int clientSocket;
    if (fdArray[0].revents & POLLIN) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&newAddr, &addrSize);
        if (clientSocket < 0) {
            std::cerr << "Error accepting client connection" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::cout << "New client connected" << std::endl;
        // Add the new client socket to the fdArray
        if (clientCount < MAX_CLIENTS) {
            clientCount++;
            fdArray[clientCount].fd = clientSocket;
            fdArray[clientCount].events = POLLIN;
        } else {
            std::cerr << "Too many clients. Connection rejected." << std::endl;
            close(clientSocket);
        }
    }
}

void handle_client_messages(struct pollfd (&fdArray)[MAX_CLIENTS + 1], int &clientCount) {
    char buffer[MAX_BUFFER_SIZE];
    for (int i = 1; i <= clientCount; i++) {
        if (fdArray[i].revents & POLLIN) {
            memset(buffer, 0, sizeof(buffer));
            int bytesRead = recv(fdArray[i].fd, buffer, sizeof(buffer), 0);
            if (bytesRead <= 0) {
                // Client disconnected or error occurred
                close(fdArray[i].fd);
                std::cout << "Client disconnected" << std::endl;
                // Remove the client from fdArray
                if (i < clientCount) {
                    fdArray[i] = fdArray[clientCount];
                }
                clientCount--;
            } else {
                HttpRequest parsedRequest;
                if(parse_request(buffer, parsedRequest))
                {
                    print_request(parsedRequest);
                    send_ok_response(fdArray[i].fd);
                }
                else
                {
                    std::cout << "Bad request!" << std::endl;
                    send_bad_request_response(fdArray[i].fd);
                }
            }
        }
    }
}

int main() {
    int serverSocket;
    init_server(serverSocket);

    // Initialize the fdArray for poll()
    struct pollfd fdArray[MAX_CLIENTS + 1]; // +1 for the server socket
    fdArray[0].fd = serverSocket;
    fdArray[0].events = POLLIN; // Server socket ready for reading

    int clientCount = 0;
	while (true) {
     
        int activity = poll(fdArray, clientCount + 1, -1); // -1 means wait indefinitely
        if (activity < 0) {
            std::cerr << "Error in poll()" << std::endl;
            exit(EXIT_FAILURE);
        }
        handle_client_connections(fdArray, serverSocket, clientCount);
        handle_client_messages(fdArray, clientCount);
        // char input;
        // std::cin >> input;
        // if (std::cin.eof())
       	// {
       	// 	std::cout << "EOF (CTRL+D) detected. Exiting the loop." << std::endl;
        //     break ;
    	// }
    	// else
    	// {
        // 	std::cout << "Input error or other termination condition." << std::endl;
    	// }   
    }
    return 0;
}