Here is a list of simple steps we need to follow to implement file upload

1. On the client side, we attempt to upload a file using a html form such as [this](responses/fileUploadClientForm.html):

2. Clicking 'upload' will produce a POST request such as [this](requests/POSTfileUpload.txt)

3. The request will be received by the server. If it is detected as a HTTP/1.1 POST request *and* the file extension is .php, we will run a [php script](cgi/upload.php) in a CGI environment on the server.

NOTE: We need to add different exit statuses for the potential outcomes to the php script.

4. Create a CGI Environment: Create environment variables like REQUEST_METHOD, QUERY_STRING, CONTENT_TYPE, CONTENT_LENGTH, etc., which mimic a typical HTTP request

5. Prepare Input Data: If your PHP script expects POST data, you'll need to prepare the POST data in the format that PHP expects (usually as stdin data for CGI scripts) use dup!!

6. Execute PHP Script: Use fork() and execve() or a similar mechanism to execute the PHP interpreter (php-cgi) with your PHP script as an argument. Pass the prepared environment variables and POST data to the PHP script

7. Send Response: After running the PHP script, we send either a `200 OK` or `400 Bad Request` HTTP response based on the exit status (0) or (1). We may also wish to capture output of the PHP script to provide an individualised error message to the Bad Request response