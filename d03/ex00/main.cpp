#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct_1("Amoeba");
	ClapTrap ct_2("Charles");

	while (1)
	{
		ct_1.attack(ct_2.getName());
		if (ct_1.checkDeath() || ct_2.checkDeath()) {
			break ;
		}
		ct_2.takeDamage(ct_1.getAd());
		if (ct_1.checkDeath() || ct_2.checkDeath()) {
			break ;
		}
		ct_2.attack(ct_1.getName());
		if (ct_1.checkDeath() || ct_2.checkDeath()) {
			break ;
		}
		ct_1.takeDamage(ct_2.getAd());
		if (ct_1.checkDeath() || ct_2.checkDeath()) {
			break ;
		}
	}

	// while (1)
	// {
	// 	ct_1.attack(ct_2.getName());
	// 	ct_2.takeDamage(ct_1.getAd());
	// 	ct_1.setEp("+");
	// 	ct_2.attack(ct_1.getName());
	// 	ct_1.takeDamage(ct_2.getAd());
	// 	ct_2.setEp("+");
	// }
	return 0;
}
