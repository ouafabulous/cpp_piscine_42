#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact {

public:

	Contact(std::string inputs[5]);
	~Contact( void );
	void setFirstName(std::string first_name);
	std::string getFirstName(void);

private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

};
#endif
