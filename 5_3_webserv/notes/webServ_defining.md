

Defining the project

# Which broswer to test with?

chrome

# What RFC's/sections to comply with?

# Which request headers must we parse?

# Which response headers must we be able to return?

# Which polling method to use: select(), kqueue(), epoll() poll()

Short answer: stick with poll despite some inefficiencies or considering using epoll.

I ruled out:
- select() as it's limited to 1024 file descriptors
- kqueue() as it's not as widely supported as poll()

1. **poll():**
   - **Advantages:**
     - Simplicity and portability, making it available on many Unix-like systems.
     - Provides basic I/O multiplexing capabilities.
   - **Disadvantages:**
     - Less efficient than `epoll()` when handling a large number of file descriptors due to the linear scan of the descriptor array.
     - Limited to monitoring file descriptors, lacking some advanced event types found in `epoll()`.

2. **epoll():**
   - **Advantages:**
     - Optimized for high-performance I/O event handling, particularly in scenarios with a large number of file descriptors.
     - Scales well with the number of descriptors, making it suitable for high-traffic servers.
     - Provides edge-triggered and level-triggered modes for better control over events.
     - Available on Linux systems.
   - **Disadvantages:**
     - Limited to Linux platforms and is not portable to other operating systems.
     - Slightly more complex to use compared to `poll()`.


# Which CGI service to support?

# Which file upload method to support and how?

simplest method of uploading a file from a browser like Chrome to a web server is using an HTML <input type="file"> form element.

RFC 1867: Form-based File Upload in HTML (<input type="file"> element and the "multipart/form-data")
RFC 2388: Returning Values from Forms: multipart/form-data," this RFC extends RFC 1867 and provides additional details on the use of "multipart/form-data" for form submissions, including file uploads.
HTML 4.01 and HTML5 specs, define the structure and behavior of web forms

How? Parsing the "multipart/form-data" request, extracting and saving uploaded files, etc.

# how to divide up the work?

One person can implement CGI

# what testing strategy?

need a combination of functionality tests and stress tests
can do both telnet tests and chrome browser automation tests