#include "BitcoinExchange.hpp"

int regex_match(const char *string)
{
    regex_t regex;
    int reti;

    /* Compile regular expression */
    // reti = regcomp(&regex, "^(19|20)\\d{2}-(0[1-9]|1[0-2])-(0[1-9]|[1-2]\\d|3[0-1])\\s\\|\\s[+]?([0-9]+([.][0-9]*)?|[.][0-9]+)$", 0);

	// reti = regcomp(&regex, "^(19|20)\\d{2}-(0[1-9]|1[0-2])-(0[1-9]|[1-2]\\d|3[0-1])$", 0);
	reti = regcomp(&regex, "^(19|20)\\d{2}$", 0);
    if (reti)
		throw std::runtime_error("Internal error");

    /* Execute regular expression */
    reti = regexec(&regex, string, 0, NULL, REG_EXTENDED);
    if (!reti)
		return 0;
    else
		throw std::runtime_error("Invalid date");
	regfree(&regex);
    return 0;
}

int main(int argc, char const *argv[])
{
	try {
		if (argc != 2)
			throw std::runtime_error("Usage: ./btc [file]");
		std::ifstream file(argv[1]);
		if (!file.is_open())
			throw std::runtime_error("Could not open file");
		std::string line;
    	while (std::getline(file, line))
    	{
			regex_match(line.c_str());
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
