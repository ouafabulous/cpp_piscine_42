#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie*	zombieHorde(int N, std::string name);

Zombie::Zombie(void) {
}
Zombie::Zombie(std::string name) : _name(name) {}
Zombie::~Zombie(void) {
	std::cout << this->getName() << " is destructed." << std::endl;
}

std::string	Zombie::getName(void) const {
	return (this->_name);
}

void	Zombie::announce(void) const{
std::cout << this->getName() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

