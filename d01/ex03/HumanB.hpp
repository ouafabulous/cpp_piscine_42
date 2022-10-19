#ifndef	HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{

private:

	Weapon		_weapon;
	std::string	_name;

public:

	HumanB(std::string name);
	HumanB(void);
	~HumanB();

	void	attack(void) const;
	void	setWeapon(Weapon weapon);

};

#endif
