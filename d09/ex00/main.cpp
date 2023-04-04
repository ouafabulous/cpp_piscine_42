#include "BitcoinExchange.hpp"

void printWithouttrailingZeros(double price)
{
	std::ostringstream os;
	os << std::fixed << price;
	std::string s = os.str();
	size_t pos = s.find_last_not_of('0');
	if (pos != std::string::npos && s[pos] == '.')
	{
		pos --;
	}
	s.erase(pos + 1);
	std::cout << s;
}

int regex_match_input(const char *string)
{
    regex_t regex;
    int reti;

	reti = regcomp(&regex, "^\\(19\\|20\\)[0-9][0-9]-\\(0[1-9]\\|1[0-2]\\)-\\(0[1-9]\\|1[0-9]\\|2[0-9]\\|3[0-1]\\)\\s|\\s\\(\\(-\\|\\+\\)\\?[0-9]\\+\\([.][0-9]\\+\\)\\?\\)$", 0);
	if (reti)
		throw std::runtime_error("Internal error");

    /* Execute regular expression */
    reti = regexec(&regex, string, 0, NULL, 0);

	//free compiled regular expression if you want to use the regex_t again
	regfree(&regex);
	if (!reti)
    	return 0;
    else if (reti == REG_NOMATCH)
		throw std::runtime_error("bad input => " + std::string(string));
	else
		throw std::runtime_error("bad input => " + std::string(string));
}

int regex_match_data(const char *string)
{
    regex_t regex;
    int reti;

	reti = regcomp(&regex, "^\\(19\\|20\\)[0-9][0-9]-\\(0[1-9]\\|1[0-2]\\)-\\(0[1-9]\\|1[0-9]\\|2[0-9]\\|3[0-1]\\),\\([0-9]\\+\\([.][0-9]\\+\\)\\?\\)$", 0);
	if (reti)
		throw std::runtime_error("Internal error");

    /* Execute regular expression */
    reti = regexec(&regex, string, 0, NULL, 0);

	//free compiled regular expression if you want to use the regex_t again
	regfree(&regex);
	if (!reti)
    	return 0;
    else if (reti == REG_NOMATCH)
		throw std::runtime_error("bad input => " + std::string(string).substr(0, 10));
	else
		throw std::runtime_error("bad input => " + std::string(string));
}

int main(int argc, char const *argv[])
{
	try {
		if (argc != 2)
			throw std::runtime_error("Usage: ./btc [input]");
		std::ifstream dataFile("data.csv");
		if (!dataFile.is_open())
			throw std::runtime_error("Could not open data");

		std::string lineData;
		std::getline(dataFile, lineData);
		BitcoinExchange data;
		while (std::getline(dataFile, lineData))
		{
			regex_match_data(lineData.c_str());
			Date date(lineData.substr(0, 4), lineData.substr(5, 2), lineData.substr(8, 2));
			double price = std::atof(lineData.substr(11, lineData.length() - 11).c_str());
			data.setMap(date, price, DATA);
		}

		std::ifstream input(argv[1]);
		if (!input.is_open())
			throw std::runtime_error("Could not open input");
		std::string line;
		std::getline(input, line);
    	while (std::getline(input, line))
    	{
			try {
			regex_match_input(line.c_str());
			Date date(line.substr(0, 4), line.substr(5, 2), line.substr(8, 2));
			double price = std::atof(line.substr(13, line.length() - 13).c_str());
			BitcoinExchange input(date, price, INPUT);
			Date adjustedDate = input.getDate(date, data.getMap());
			std::cout << adjustedDate << " => " << std::fixed << std::noshowpoint;
			printWithouttrailingZeros(input.getValue(date));
			std::cout <<  " = ";
			printWithouttrailingZeros(data.getValue(adjustedDate)*input.getValue(date));
			std::cout << std::endl;
			}
			catch (std::exception &e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
			}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	return 0;
}
