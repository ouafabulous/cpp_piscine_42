#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>

int	main( void ) {

std::string			opt1 = "ADD";
std::string			opt2 = "SEARCH";
std::string			opt3 = "EXIT";
std::string			cmd;
std::string			inputs[5];
std::string			id_txt;
int					id;
bool				is_ok;
PhoneBook			repertoire;

std::cout << "Choose an option amongst the following: ADD, SEARCH, EXIT: ";
while (std::getline(std::cin, cmd) && cmd != opt3)
{
	if (cmd == opt1)
		{
			std::cout << "First name: ";
			std::cin >> inputs[0];
			std::cout << "Last name: ";
			std::cin >> inputs[1];
			std::cout << "Nickname: ";
			std::cin >> inputs[2];
			std::cout << "Phone number: ";
			std::cin >> inputs[3];
			std::cout << "Darkest secret: ";
			std::cin >> inputs[4];
			repertoire.fill_contact(inputs);
		}
	else if (cmd == opt2)
	{
		is_ok = false;
		while (!is_ok)
		{
		std::cout<< "Enter the contact Id (in range 0-7): ";
		std::cin >> id_txt;
		try {
			std::istringstream(id_txt) >> id;
			if (id >= 0 && id <= 7)
				is_ok = true;
		}
		catch (std::exception &err)
		{
			is_ok = false;
		}
		}
		repertoire.print_contact(id);
	}
//	std::cout << "Choose an option amongst the following: ADD, SEARCH, EXIT: ";
}
	return (0);
}
