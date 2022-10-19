#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie	*z;

	(void)name;
	z = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		z[i].setName(name);
		z[i].announce();
	}
	return (z);
}
