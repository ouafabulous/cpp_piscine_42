#include "Zombie.hpp"

int main()
{
	Zombie	*zh;

	zh = zombieHorde(5, "default");

	delete [] zh;

	return 0;
}

