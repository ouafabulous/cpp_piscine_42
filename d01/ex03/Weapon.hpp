#ifndef WEAPON_H
# define WEAPON_H

#include <string>
#include <iostream>

#define BLUE    "\033[1m\033[34m"
#define GREEN   "\033[1m\033[32m"
#define RESET   "\033[0m"

class Weapon
{

private:

	std::string	_type;

public:

	Weapon(std::string name);
	Weapon();
	~Weapon();

	std::string const	&getType(void) const;
	void		setType(std::string type);
};


#endif
