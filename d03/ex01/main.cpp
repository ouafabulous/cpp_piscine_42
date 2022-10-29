#include "ScavTrap.hpp"

int main()
{
	ScavTrap	st_1("Amoeba");
	ClapTrap	ct_1("Clappinette");
	ScavTrap	st_2("Charles");

	st_1.guardGate();
	st_2.guardGate();

	// while (1)
	// {
	// 	st_1.attack(st_2.getName());
	// 	if (st_1.checkDeath() || st_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	st_2.takeDamage(st_1.getAd());
	// 	if (st_1.checkDeath() || st_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	st_2.attack(st_1.getName());
	// 	if (st_1.checkDeath() || st_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	st_1.takeDamage(st_2.getAd());
	// 	if (st_1.checkDeath() || st_2.checkDeath()) {
	// 		break ;
	// 	}
	// }
	// while (1)
	// {
	// 	ct_1.attack(st_2.getName());
	// 	if (ct_1.checkDeath() || st_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	st_2.takeDamage(ct_1.getAd());
	// 	if (ct_1.checkDeath() || st_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	st_2.attack(ct_1.getName());
	// 	if (ct_1.checkDeath() || st_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ct_1.takeDamage(st_2.getAd());
	// 	if (ct_1.checkDeath() || st_2.checkDeath()) {
	// 		break ;
	// 	}
	// }

	while (1)
	{
		st_1.attack(st_2.getName());
		if (st_1.checkDeath() || st_2.checkDeath()) {
			break ;
		}
		st_2.takeDamage(st_1.getAd());
		if (st_1.checkDeath() || st_2.checkDeath()) {
			break ;
		}
		st_1.beRepaired(HP_ST - st_1.getHp());
		if (st_1.checkDeath() || st_2.checkDeath()) {
			break ;
		}
		st_2.attack(st_1.getName());	// 	st_1.takeDamage(st_2.getAd());
		if (st_1.checkDeath() || st_2.checkDeath()) {
			break ;
		}
		st_1.takeDamage(st_2.getAd());
		if (st_1.checkDeath() || st_2.checkDeath()) {
			break ;
		}
		st_2.beRepaired(HP_ST - st_2.getHp());
		if (st_1.checkDeath() || st_2.checkDeath()) {
			break ;
		}
	}
	return 0;
}
