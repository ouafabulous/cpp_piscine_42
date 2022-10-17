#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.hpp"
#include <string>

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook( void );

	void	fill_contact(std::string inputs[5]);
	void	print_contacts(void);
	void	print_contact(int id, int type);

private:
	Contact	_contacts[8];
	int		_i;
};

#endif
