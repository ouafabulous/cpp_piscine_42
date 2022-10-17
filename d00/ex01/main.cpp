#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cstdlib>

void protected_cout(std::string prompt, std::string *cmd)
{
	std::cout << prompt;
	std::getline(std::cin, *cmd);
	if (std::cin.eof())
	{
		std::cin.ignore(INT_MAX, '\n');
		exit(1);
	}
}

void recursive_print(PhoneBook repertoire)
{
	bool is_ok;
	std::string id_txt;
	int id;

	is_ok = false;
	while (!is_ok)
	{
		protected_cout("Enter a contact Id (in range 0-7): ", &id_txt);
		try
		{
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
	recursive_print(repertoire);
}

int main(void)
{

	std::string opt1 = "ADD";
	std::string opt2 = "SEARCH";
	std::string opt3 = "EXIT";
	std::string cmd;
	std::string inputs[5];
	PhoneBook repertoire;

	while (1)
	{
		protected_cout("Choose an option amongst the following: ADD, SEARCH, EXIT: ", &cmd);
		if (cmd == opt1)
		{
			protected_cout("First name: ", &(inputs[0]));
			protected_cout("Last name: ", &(inputs[1]));
			protected_cout("Nickname: ", &(inputs[2]));
			protected_cout("Phone number: ", &(inputs[3]));
			protected_cout("Darkest secret: ", &(inputs[4]));
			repertoire.fill_contact(inputs);
		}
		else if (cmd == opt2)
		{
			recursive_print(repertoire);
		}
		else if (cmd == opt3 || std::cin.eof())
		{
			break;
		}
		else
		{
			continue;
		}
		std::cin.ignore(INT_MAX, '\n');
	}
	return (0);
}
