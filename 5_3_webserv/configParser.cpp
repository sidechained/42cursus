// clear; c++ -Wall -Werror -Wextra -std=c++98 configParser.cpp && ./a.out

// TODO:
// - convert to class
// - Q: how to handle server port defaults?
// - check that each server has a port, otherwise error and exit
// - strip trailing whitespace on strings to avoid many parsing errors
// - create a range of config files for testing
// - have a MAX_SERVERS limit (here or elsewhere?)
// - write an example main loop for how PollingServers might be constructed

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>

#define ERR_OPEN "Unable to open config file"
#define ERR_PARSE "Unable to parse config file"
#define ERR_PARSE_KEY "First line of server block not "
#define ERR_PARSE_EMPTY "Line empty"
#define ERR_PARSE_INDENT "Line not indented by tab"
#define ERR_PARSE_NOKEY "No key found in line"
#define ERR_PARSE_SPACE "Space doesn't follow key"
#define ERR_PARSE_REDIR "Redirections should only contain two elements"
#define ERR_PARSE_SERVER "Server block should end with an empty line"
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
	std::string uploads;
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

#include "configParserPrint.cpp"

void init_server(Server &server)
{
	// already empty std::vector<ListenPort> listenPorts
	server.name = "";
	server.client_max_body_size_mb = 1;
	// already empty std::map<std::string, std::string> error_pages;
}

void init_location(Location &location)
{
	location.methods.push_back("GET");
	location.methods.push_back("POST");
	location.methods.push_back("DELETE");
	location.redirection.oldURL = "";
	location.redirection.newURL = "";
	location.alias = "";
	location.uploads = "";
	location.autoindex = false;
	location.index = "";
}

void error_exit(std::string err1, std::string err2)
{
	std::cerr << err1 << std::endl;
	if (!err2.empty())
		std::cerr << "[" << err2 << "]" << std::endl;
	exit(EXIT_FAILURE);
}

void detect_line(std::string &line, std::string keyToMatch) {
	std::string err_str = std::string(ERR_PARSE_KEY) + "'" + keyToMatch + ":'";
	if(line != keyToMatch + ":")
		error_exit(ERR_PARSE, err_str);
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
		error_exit(ERR_PARSE, ERR_PARSE_EMPTY);
	for (int i = 0; i < numTabs; i++)
	{
		if (line[i] != '\t')
			error_exit(ERR_PARSE, ERR_PARSE_INDENT);
	}
	line.erase(0, numTabs); // strip the tab
}

void extract_key(std::string line, std::string &key, std::size_t &colonPos) {
	colonPos = line.find(':');
	if (colonPos == std::string::npos)
		error_exit(ERR_PARSE, ERR_PARSE_NOKEY);
	key = line.substr(0, colonPos);
}

void extract_value(std::string line, std::string &value, std::size_t &colonPos) {
	value = line.substr(colonPos + 1);
	if (value.empty() || value[0] != ' ')
		error_exit(ERR_PARSE, ERR_PARSE_SPACE);
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
	location.methods.clear(); // wipe out the methods that were put there by initialisation
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
			error_exit(ERR_PARSE, ERR_PARSE_REDIR);
    }
}

void extract_locations(Server &server, std::fstream &configFile, std::string &line, bool &gotLine)
{
	std::getline(configFile, line);
	while(count_tab_indents(line, 2))
	{
		std::string locationKey;
		std::size_t locationColonPos;
		detect_and_strip_tab_indents(line, 2);
		extract_key(line, locationKey, locationColonPos);
		init_location(server.locations[locationKey]);
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
			} else if (locEntryKey == "uploads") {
				extract_value(line, locEntryValue, locEntryColonPos);
				server.locations[locationKey].uploads = locEntryValue;	
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

void extract_error_pages(Server &server, std::fstream &configFile, std::string &line, bool &gotLine)
{
	std::getline(configFile, line);
	while(count_tab_indents(line, 2))
	{
		detect_and_strip_tab_indents(line, 2);
		std::string errorKey;
		std::string errorValue;
		std::size_t errorColonPos;
		extract_key(line, errorKey, errorColonPos);
		extract_value(line, errorValue, errorColonPos);
		server.error_pages[errorKey] = errorValue;
		std::getline(configFile, line);
		gotLine = true;
	}	
}

void extract_server(std::fstream &configFile, std::string &line, std::vector<Server> &servers)
{
	Server server;
	init_server(server);
	std::getline(configFile, line);
	detect_line(line, "server");
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
		std::string value;
		std::size_t colonPos;
		extract_key(line, key, colonPos);
		if (key == "ports") {
			extract_value(line, value, colonPos);
			extract_ports(value, server.listenPorts);
		} else if (key == "name") {
			extract_value(line, value, colonPos);
			server.name = value;
		} else if (key == "client_max_body_size_mb") {
			extract_value(line, value, colonPos);
			std::istringstream iss(value);
			iss >> server.client_max_body_size_mb;
		} else if (key == "error_pages") {
			extract_error_pages(server, configFile, line, gotLine);
		} else if (key == "locations") {
			extract_locations(server, configFile, line, gotLine);			
		}				
	}
	if(!line.empty())
		error_exit(ERR_PARSE, ERR_PARSE_SERVER);
	servers.push_back(server);
}

int main()
{
	std::fstream configFile("specs/ourServerConfigFile.txt");
	if(!configFile.is_open())
		error_exit(ERR_OPEN, ""); // "" correct way to handle?
	std::string line;
	std::vector<Server> servers;
	while(1)
	{
		extract_server(configFile, line, servers);
		if (configFile.eof())
			break;
	}
	printServers(servers);
	configFile.close();
}

