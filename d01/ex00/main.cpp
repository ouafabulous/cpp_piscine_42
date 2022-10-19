#include "Zombie.hpp"
#include <string>

int main()
{
	Zombie*	z;

	z = newZombie("heapZombie");
	randomChump("stackZombie");
	delete z;
	return 0;
}


