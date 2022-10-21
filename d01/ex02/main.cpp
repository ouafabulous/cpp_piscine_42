#include <string>
#include <iostream>

#define YELLOW  "\033[1m\033[33m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define RESET   "\033[0m"

int main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << CYAN << "• The memory address of the string variable: " << &string << RESET << std::endl;
	std::cout << MAGENTA << "• The memory address held by stringPTR: " << stringPTR << RESET << std::endl;
	std::cout << YELLOW << "• The memory address held by stringREF: " << &stringREF << RESET << std::endl;
	std::cout << "" << std::endl;
	std::cout << CYAN << "• The value of the string variable: " << string << RESET << std::endl;
	std::cout << MAGENTA << "• The value pointed to by stringPTR: " << *stringPTR << RESET << std::endl;
	std::cout << YELLOW << "• The value pointed to by stringREF: " << stringREF << RESET << std::endl;

	return 0;
}
