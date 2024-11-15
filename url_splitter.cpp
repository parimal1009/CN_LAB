#include <iostream>
#include <regex>
#include <string>

int main() {
    // Get URL from user input
    std::string url;
    std::cout << "Enter a URL: ";
    std::getline(std::cin, url);

    // Regex pattern to extract different parts of the URL
    std::regex url_regex(R"((https?)://([^/:]+)(:\d+)?(/.*)?)");
    std::smatch url_match;

    if (std::regex_match(url, url_match, url_regex)) {
        // URL parts: Scheme (protocol), Host, Port (optional), Path (file name)
        std::string protocol = url_match[1];
        std::string host = url_match[2];
        std::string port = url_match[3];
        std::string path = url_match[4];

        // Print URL details
        std::cout << "URL is: " << url << std::endl;
        std::cout << "Protocol is: " << protocol << std::endl;
        std::cout << "Host is: " << host << std::endl;

        // Handle port number; if not specified, use the default port
        if (!port.empty()) {
            std::cout << "Port is: " << port.substr(1) << std::endl; // Remove ':' from port
        } else {
            std::cout << "Port is: not specified" << std::endl;
        }

        // Default port based on the protocol
        std::cout << "Default port is: " << (protocol == "https" ? 443 : 80) << std::endl;

        // Extract file name from path (optional)
        size_t lastSlash = path.find_last_of('/');
        std::string fileName = (lastSlash != std::string::npos) ? path.substr(lastSlash + 1) : path;
        std::cout << "File name is: " << fileName << std::endl;
    } else {
        std::cerr << "Invalid URL format." << std::endl;
    }

    return 0;
}
