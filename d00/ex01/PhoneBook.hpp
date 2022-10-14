#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.hpp"
#include <string>

class PhoneBook {

Public:

	PhoneBook( void );
	~PhoneBook( void );

Private:
	Contact	contact[8](std::string inputs[5]);

};

#endif
