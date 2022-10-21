#ifndef	HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{

private:

	std::string	_name;
	Weapon		*_weapon;

public:

	HumanB(std::string name);
	HumanB(void);
	~HumanB();

	void	attack(void) const;
	void	setWeapon(Weapon &weapon);

};

#endif
