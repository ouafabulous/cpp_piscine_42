#include <string>
#include "Contact.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

void	Contact::setFirstName(std::string first_name) {
	this->_FirstName = first_name;
	return ;
}

std::string	Contact::getFirstName(void) {
	return (this->_FirstName);
}

void	Contact::setLastName(std::string last_name) {
	this->_LastName = last_name;
	return ;
}

std::string	Contact::getLastName(void) {
	return (this->_LastName);
}

void	Contact::setNickName(std::string nickname) {
	this->_Nickname = nickname;
	return ;
}

std::string	Contact::getNickName(void) {
	return (this->_Nickname);
}

void	Contact::setPhoneNumber(std::string phone_number) {
	this->_PhoneNumber = phone_number;
}

std::string	Contact::getPhoneNumber(void) {
	return (this->_PhoneNumber);
}

void	Contact::setDarkestSecret(std::string darckest_secret) {
	this->_DarkestSecret = darckest_secret;
	return ;
}

std::string	Contact::getDarkestSecret(void) {
	return (this->_DarkestSecret);
}
