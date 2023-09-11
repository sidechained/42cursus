# Curl

GET /resource HTTP/1.1
Host: api.example.com
User-Agent: curl/7.68.0
Accept: application/json
Connection: close

POST /resource HTTP/1.1
Host: api.example.com
User-Agent: curl/7.68.0
Accept: application/json
Content-Type: application/json
Content-Length: 25
Connection: close

DELETE /resource/123 HTTP/1.1
Host: api.example.com
User-Agent: curl/7.68.0
Connection: close

HTTP/1.1 400 Bad Request
Content-Type: text/plain
Content-Length: 25
Connection: close

Bad Request: Invalid Syntax

# Chrome

treat header names as case-insensitive
treat header values as case-sensitive

header name
colon (":") separator
optional leading whitespace
header value
optional trailing newline ("\r\n").
For example: Header-Name: Header-Value\r\n.

Line Endings: HTTP headers are separated by "\r\n" (carriage return and line feed), and the headers section is terminated with an empty line ("\r\n\r\n").

Header Fields: HTTP headers can have multiple fields with the same name. When parsing, you may need to handle multiple instances of a header field by appending them together, if necessary.

Continuation Lines: Header lines can be wrapped onto multiple lines if the continuation line starts with a space or a horizontal tab. When parsing, concatenate these lines to form the complete header value.

Header Value Trimming: Trim leading and trailing whitespaces from header values to ensure consistency.

Handling Special Headers: Some headers have special handling requirements, like Cookie and Set-Cookie, which contain multiple values separated by semicolons.

Content-Length: If present, the Content-Length header indicates the length of the request body in bytes.

Host Header: The Host header is required in HTTP/1.1 requests and specifies the domain name of the server (e.g., Host: www.example.com).

User-Agent: The User-Agent header can provide information about the client making the request. However, don't rely on it for critical decisions as it can be spoofed or omitted.

Connection Header: The Connection header may specify options for managing the connection, like Connection: close, which indicates that the connection should be closed after the response.

Content-Type: The Content-Type header specifies the media type of the request body. It's important for parsing the request body correctly.

Accept-Encoding: The Accept-Encoding header can indicate the supported content encodings, which can be useful for handling compressed responses.

Query Parameters: If the request includes a query string (part of the URL after the "?"), parse and handle it separately from the headers.

Security Considerations: Be cautious when handling user-supplied headers and values to prevent security vulnerabilities like header injection and response splitting attacks.

Error Handling: Be prepared to handle malformed headers or missing required headers gracefully and return appropriate HTTP error responses (e.g., 400 Bad Request).

Library Support: Consider using established HTTP parsing libraries or frameworks available in your programming language, as they can simplify the parsing process and handle edge cases.

Remember that while these are general guidelines for parsing HTTP/1.1 request headers, specific requirements may vary depending on your application and use case. Always refer to the HTTP/1.1 specification (RFC 2616) for the most accurate and detailed information on HTTP header parsing.
