void printRedirection(const Redirection& redirection) {
    std::cout << "      Redirection: oldURL = \"" << redirection.oldURL << "\", newURL = \"" << redirection.newURL << "\"" << std::endl;
}

void printLocation(const Location& location) {
    std::cout << "      Methods:";
    for (std::vector<std::string>::const_iterator it = location.methods.begin(); it != location.methods.end(); ++it) {
        std::cout << " \"" << *it << "\"";
    }
    std::cout << std::endl;
    printRedirection(location.redirection);
    std::cout << "      Alias: \"" << location.alias << "\"" << std::endl;
    std::cout << "      uploads: \"" << location.uploads << "\"" << std::endl;
    std::cout << "      Autoindex: " << (location.autoindex ? "true" : "false") << std::endl;
    std::cout << "      Index: \"" << location.index << "\"" << std::endl;
}

void printServers(const std::vector<Server>& servers) {
    for (size_t i = 0; i < servers.size(); ++i) {
        const Server& server = servers[i];
        std::cout << "Server " << i + 1 << ":" << std::endl;
        std::cout << "  Ports:";
        for (std::vector<ListenPort>::const_iterator it = server.listenPorts.begin(); it != server.listenPorts.end(); ++it) {
            std::cout << " " << it->port << "(" << (it->dfault ? "default" : "non-default") << ")";
        }
        std::cout << std::endl;
        std::cout << "  Name: \"" << server.name << "\"" << std::endl;
        std::cout << "  Client Max Body Size (MB): " << server.client_max_body_size_mb << std::endl;
        std::cout << "  Error Pages:" << std::endl;
        for (std::map<std::string, std::string>::const_iterator it = server.error_pages.begin(); it != server.error_pages.end(); ++it) {
            std::cout << "    \"" << it->first << "\": \"" << it->second << "\"" << std::endl;
        }
        std::cout << "  Locations:" << std::endl;
        for (std::map<std::string, Location>::const_iterator it = server.locations.begin(); it != server.locations.end(); ++it) {
            std::cout << "    \"" << it->first << "\":" << std::endl;
            printLocation(it->second);
        }
    }
}
