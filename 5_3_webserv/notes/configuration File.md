

IMPLEMENT AS YAML

- The first server for a host:port will be the default for this host:port
- (that means it will answer to all the requests that don’t belong to an other server).

- if a request comes in for a host and port for which there is no specific server configuration defined, the default server configuration will handle that request. It essentially acts as a catch-all or fallback configuration for requests that do not match any other defined servers.

- must be able to liste on multiple ports

- port is mandatory, default server is optional (only one can be default)
- server_name is optional (default is no name)
- client_max_body_size is optional (default in NGINX is 1MB)

location:
- `methods` specifies accepted HTTP methods and is optional (default is to accept GET POST DELETE)
- `redir` specifies url to redirect to for a given url (default is no redirection)
- `alias` specifies location to use instead of the given location (default is no alias)
- `autoindex' turns directory listing on (default is off, overrides `index`)
- 'index index.html' provides a default index page (default is off, overriden by autoindex)
- `uploads /uploads1` is optional (default is off)

// CHATGPT request
write me two server sections of a NGINX configuration file that specifies:

- the port and host of each ’server’
- the server name
- typical default error pages
- the client body size limit
Note:  The first server for a host:port will be the default for this host:port (that means it will answer to all the requests that don’t belong to an other server).

Also include two location sections for each server section, covering the following rules/configuration:

- a list of accepted HTTP methods for the route
- a HTTP redirection
- a directory or a file from where the file should be searched (for example, if url /kapouet is rooted to /tmp/www, url /kapouet/pouic/toto/pouet is /tmp/www/pouic/toto/pouet).
- directory listing turned on
- a default file to answer if the request is a directory
- allow CGI based on .php for file upload
- make the route able to accept uploaded files and configure where they should be saved