#include "Zombie.hpp"
#include <string>

int main()
{
	Zombie*	z;

	randomChump("stackZombie");
	z = newZombie("heapZombie");
	z->announce();
	delete z;
	return 0;
}


