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
std::string			id;
int					i;
bool				is_ok;
PhoneBook			repertoire = Phonebook();

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
			repertoire(inputs);
		}
	else if (cmd == opt2)
	{
		is_ok = false;
		while (!is_ok)
		{
		std::cout<< "Enter the contact Id (in range 0-7): ";
		std::cin >> id;
		try {
			i = std::stoi(id);
			is_ok = true;
		}
		catch (exception &err)
		{
			is_ok = false;
		}
		}
		std::cout <<
	}
	else
	return (0);
}
