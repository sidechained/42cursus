// clear; c++ -Wall -Werror -Wextra -std=c++98 configParser.cpp && ./a.out

// Instrutions on how the config file must be formatted:
// - 

// TODO:
// - populate the structs with defaults first
// - FIX: why do ports not print?
// - should we check the location path for validity...or let the server class do that? [the latter]

// YAML-style parsing rules...
// file must start with "server:"
// server block ends with \n

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>

struct ListenPort
{
	int port;
	bool dfault;
};

struct Redirection
{
	std::string oldURL;
	std::string newURL;
};

struct Location
{
	std::vector<std::string> methods;
	Redirection redirection;
	std::string alias;    
	std::string allowUpload;
	bool autoindex;
	std::string index;
};

struct Server
{
	std::vector<ListenPort> listenPorts;
	std::string name;
	std::map<std::string, std::string> error_pages;
	int client_max_body_size_mb;
	std::map<std::string, Location> locations;
};

void detect_line(std::fstream &configFile, std::string &line, std::string keyToMatch) {
	std::getline(configFile, line);
	if(line != keyToMatch + ":") {
		std::cerr << "Unable to parse config file (first line not 'server:')." << std::endl;
		exit(EXIT_FAILURE);
	}
}

bool count_tab_indents(std::string &line, int numTabs) {
	if (line.empty())
		return false;
	for (int i = 0; i < numTabs; i++)
	{
		if (line[i] != '\t')
			return false;
	}
	return true;
}

void detect_and_strip_tab_indents(std::string &line, int numTabs) {
	// next line must be indented by a single tab
	if (line.empty())
	{
		std::cerr << "Unable to parse config file (line empty)." << std::endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < numTabs; i++)
	{
		if (line[i] != '\t')
		{
			std::cerr << "Unable to parse config file (line not indented by tab)." << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	line.erase(0, numTabs); // strip the tab
}

void extract_key(std::string line, std::string &key, std::size_t &colonPos) {
	colonPos = line.find(':');
	if (colonPos == std::string::npos) {
		std::cerr << "Unable to parse config file (no key found in line)." << std::endl;
		exit(EXIT_FAILURE);
	}
	key = line.substr(0, colonPos);
}

void extract_value(std::string line, std::string &value, std::size_t &colonPos) {
	value = line.substr(colonPos + 1);
	if (value.empty() || value[0] != ' ') {
		std::cerr << "Unable to parse config file (space doesn't follow key)." << std::endl;
		exit(EXIT_FAILURE);
	}
	value.erase(0, 1); // strip the space
}

void extract_ports(std::string portString, std::vector<ListenPort> &listenPorts)
{
    ListenPort listenPort;
    std::istringstream iss(portString);
	int port;
    while (iss >> port) {
		listenPort.port = port;
		listenPort.dfault = false;
        listenPorts.push_back(listenPort);
    }
}

void extract_methods(std::string methodString, Location &location)
{
    std::istringstream iss(methodString);
	std::string method;
    while (iss >> method) {
		location.methods.push_back(method);
    }
}

void extract_redir(std::string redirString, Location &location)
{
    std::istringstream iss(redirString);
	std::string redir;
	int elementCount = 0;
    while (iss >> redir) {
		if (elementCount == 0)
			location.redirection.oldURL = redir;
		if (elementCount == 1)
			location.redirection.newURL = redir;
		elementCount++;
		if (elementCount > 2)
		{
			std::cerr << "Unable to parse config file (redirections should only contain two elements)." << std::endl;
			exit(EXIT_FAILURE);
		}
    }
}

// Helper function to print a Redirection struct
void printRedirection(const Redirection& redirection) {
    std::cout << "  	  Redirection: oldURL = " << redirection.oldURL << ", newURL = " << redirection.newURL << std::endl;
}

// Helper function to print a Location struct
void printLocation(const Location& location) {
    std::cout << "  	  Methods:";
    for (std::vector<std::string>::const_iterator it = location.methods.begin(); it != location.methods.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
    printRedirection(location.redirection);
    std::cout << "  	  Alias: " << location.alias << std::endl;
    std::cout << "  	  AllowUpload: " << location.allowUpload << std::endl;
    std::cout << "  	  Autoindex: " << (location.autoindex ? "true" : "false") << std::endl;
    std::cout << "  	  Index: " << location.index << std::endl;
}

// Main function to print a Server struct
void printServers(const std::vector<Server>& servers) {
    for (size_t i = 0; i < servers.size(); ++i) {
        const Server& server = servers[i];
        std::cout << "Server " << i + 1 << ":" << std::endl;
        std::cout << "  Ports:";
        for (std::vector<ListenPort>::const_iterator it = server.listenPorts.begin(); it != server.listenPorts.end(); ++it) {
            std::cout << " " << it->port << "(" << (it->dfault ? "true" : "false") << ")";
        }
        std::cout << std::endl;
        std::cout << "  Name: " << server.name << std::endl;
		std::cout << "  Client Max Body Size (MB): " << server.client_max_body_size_mb << std::endl;
        std::cout << "  Error Pages:" << std::endl;
        for (std::map<std::string, std::string>::const_iterator it = server.error_pages.begin(); it != server.error_pages.end(); ++it) {
            std::cout << "    " << it->first << ": " << it->second << std::endl;
        }
        std::cout << "  Locations:" << std::endl;
        for (std::map<std::string, Location>::const_iterator it = server.locations.begin(); it != server.locations.end(); ++it) {
            std::cout << "	" << it->first << ":" << std::endl;
            printLocation(it->second);
        }
    }
}

int main()
{
	std::vector<Server> servers;
	std::fstream configFile("specs/ourServerConfigFile.txt");
	if(!configFile.is_open()) {
		std::cerr << "Unable to open config file." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	// first line must be "server:", if so continue and instantiate a server
	detect_line(configFile, line, "server");
	Server server;
	// get next line, then loop around the subsequent lines until we encounter an empty line
	bool gotLine = false;
	while(1) {
		if (!gotLine)
			std::getline(configFile, line);
		else
			gotLine = false;
		if (line.empty())
			break;
		detect_and_strip_tab_indents(line, 1);
		std::string key;
		std::size_t colonPos;
		extract_key(line, key, colonPos);
		if (key == "ports") {
			std::string value;
			extract_value(line, value, colonPos);
			extract_ports(value, server.listenPorts);
		} else if (key == "name") {
			std::string value;
			extract_value(line, value, colonPos);
			server.name = value;
		} else if (key == "client_max_body_size_mb") {
			std::string value;
			extract_value(line, value, colonPos);
			std::istringstream iss(value);
			iss >> server.client_max_body_size_mb;
		} else if (key == "error_pages") {
			std::getline(configFile, line);
			while(count_tab_indents(line, 2))
			{
				detect_and_strip_tab_indents(line, 2);
				std::string errorKey;
				std::size_t errorColonPos;
				extract_key(line, errorKey, errorColonPos);
				std::string errorValue;
				extract_value(line, errorValue, errorColonPos);
				server.error_pages[errorKey] = errorValue;
				std::getline(configFile, line);
				gotLine = true;
			}
		} else if (key == "locations") {
			std::getline(configFile, line);
			while(count_tab_indents(line, 2))
			{
				std::string locationKey;
				std::size_t locationColonPos;
				detect_and_strip_tab_indents(line, 2);
				extract_key(line, locationKey, locationColonPos);
				std::getline(configFile, line);
				while(count_tab_indents(line, 3))
				{
					detect_and_strip_tab_indents(line, 3);
					std::string locEntryKey;
					std::size_t locEntryColonPos;
					extract_key(line, locEntryKey, locEntryColonPos);
					std::string locEntryValue;
					if (locEntryKey == "methods") {
						extract_value(line, locEntryValue, locEntryColonPos);
						extract_methods(locEntryValue, server.locations[locationKey]);
					} else if (locEntryKey == "redir") {
						extract_value(line, locEntryValue, locEntryColonPos);
						extract_redir(locEntryValue, server.locations[locationKey]);
					} else if (locEntryKey == "alias") {
						extract_value(line, locEntryValue, locEntryColonPos);
						server.locations[locationKey].alias = locEntryValue;
					} else if (locEntryKey == "allow_upload") {
						extract_value(line, locEntryValue, locEntryColonPos);
						server.locations[locationKey].allowUpload = locEntryValue;	
					} else if (locEntryKey == "index") {
						extract_value(line, locEntryValue, locEntryColonPos);
						server.locations[locationKey].index = locEntryValue;											
					} else if (locEntryKey == "autoindex") {
						extract_value(line, locEntryValue, locEntryColonPos);
						if (locEntryValue == "true")
							server.locations[locationKey].autoindex = true;
					}
					std::getline(configFile, line);
					gotLine = true;
				}
			}
			
		}				
	}
	servers.push_back(server);
	printServers(servers);
	configFile.close();
}

