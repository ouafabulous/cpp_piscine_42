#include <string>
#include "contact.hpp"

Contact::Contact(std::string inputs[5]) :first_name(inputs[0]), last_name(inputs[1]), nickname(inputs[2]), phone_number(inputs[3]), darkest_secret(inputs[4]) {
	return;
}

Contact::~Contact( void ) {
	return;
}

