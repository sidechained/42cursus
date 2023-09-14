# The basics:

- a webServ config file consists or one more more 'server' blocks
- for each server block, a single port is mandatory, everything else is optional and will be set to default if not specified (see spec below)
- options may be specified in any order
- beware of trailing whitespace on all lines (it is currently not stripped)
- no checking for validity is done at this stage (that should be done by the server class itself)

To be valid, the config file must be formatted as follows:

## Servers:
- each server block must start with an unindented "server:" command and end with an empty line (or EOF)
- subsequent options belonging to this server must be indented by a single tab
- the options are 'ports', 'name', 'client_max_body_size_mb', 'error_pages' and 'locations'
- 'error_pages' should contain one or more lines idented by two tabs representing an error code and page (i.e. 404: /404.html)

## Locations:
- 'locations' specifies options for one or more paths
-- the path of the location is idented by two tabs and options related to the path are idented by three tabs
-- the options are 'methods', 'redir', 'alias', 'index', 'autoindex' and 'uploads'

# Initialisation:

Every time we create a server or location 'object' we initialise it according to the spec below.
- client_max_body_size_mb is set to 1MB
- location methods are set to GET POST DELETE
- everything else is initialised as an empty string(""), vector/map with no elements, or as 'false'

A default initialisation might look like this:
```
Server:
    Ports: empty std::vector<ListenPort> listenPorts;
    Name: ""
    Client Max Body Size (MB): 1
    Error Pages: empty std::map<std::string, std::string> error_pages;
Location:
    Methods: GET POST DELETE
    Redirection: oldURL = "", newURL = ""
    Alias: ""
    uploads: ""
    Autoindex: false
    Index: ""
```