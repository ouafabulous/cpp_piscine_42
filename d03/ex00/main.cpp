#include "ClapTrap.hpp"

int main()
{
	ClapTrap			ct_1("Amoeba");
	ClapTrap			ct_2("Charles");

	while (!ct_1.checkDeath() && !ct_2.checkDeath())
	{
	ct_1.attack(ct_2.getName());
	ct_2.takeDamage(ct_1.getAd());
	ct_2.attack(ct_1.getName());
	ct_1.takeDamage(ct_2.getAd());
	}
	return 0;
}

