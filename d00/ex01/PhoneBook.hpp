#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.hpp"
#include <string>

class PhoneBook {

public:

	void	fill_contacts(std::string inputs[5]);

	PhoneBook(std::string inputs[5]);
	~PhoneBook( void );

private:
	Contact	contacts[8];


};

#endif
