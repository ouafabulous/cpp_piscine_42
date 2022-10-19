#include "Zombie.hpp"
#include <string>

Zombie*	newZombie(std::string name) {
	Zombie	*z;

	z = new Zombie(name);
	return (z);
}

