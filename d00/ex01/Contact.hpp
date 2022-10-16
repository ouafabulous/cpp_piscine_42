#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact {

public:

	Contact(void);
	Contact(std::string inputs[5]);
	~Contact(void);

	void		setFirstName(std::string first_name);
	std::string	getFirstName(void);
	void		setLastName(std::string last_name);
	std::string	getLastName(void);
	void		setNickName(std::string nickname);
	std::string	getNickName(void);
	void		setPhoneNumber(std::string phonenumber);
	std::string	getPhoneNumber(void);
	void		setDarkestSecret(std::string darkestnumber);
	std::string	getDarkestSecret(void);

private:

	std::string	_FirstName;
	std::string	_LastName;
	std::string	_Nickname;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;

};

#endif
