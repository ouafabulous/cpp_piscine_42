#include "HumanB.hpp"

HumanB::HumanB(void) {}

HumanB::HumanB(std::string name) : _name(name) , _weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::attack(void) const{
	std::cout << GREEN << _name << " attacks with their " << _weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
