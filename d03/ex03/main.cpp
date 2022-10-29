#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{

	// DiamondTrap	dt_1("Shine");
	// FragTrap	ft_2("Charles");

	// dt_1.whoAmI();
	// ft_2.highFivesGuys();

	// while (1)
	// {
	// 	dt_1.attack(ft_2.getName());
	// 	if (dt_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ft_2.takeDamage(dt_1.getAd());
	// 	if (dt_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ft_2.attack(ct_1.getName());
	// 	if (dt_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ct_1.takeDamage(ft_2.getAd());
	// 	if (dt_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// }

	DiamondTrap	dt_1("Shine");
	DiamondTrap	dt_2("Bright");

	dt_1.guardGate();
	dt_1.highFivesGuys();
	dt_1.whoAmI();

	while (1)
	{
		dt_1.attack(dt_2.getName());
		if (dt_1.checkDeath() || dt_2.checkDeath()) {
			break ;
		}
		dt_2.takeDamage(dt_1.getAd());
		if (dt_1.checkDeath() || dt_2.checkDeath()) {
			break ;
		}
		dt_1.beRepaired(HP_ST - dt_1.getHp());
		if (dt_1.checkDeath() || dt_2.checkDeath()) {
			break ;
		}
		dt_2.attack(dt_1.getName());	// 	st_1.takeDamage(st_2.getAd());
		if (dt_1.checkDeath() || dt_2.checkDeath()) {
			break ;
		}
		dt_1.takeDamage(dt_2.getAd());
		if (dt_1.checkDeath() || dt_2.checkDeath()) {
			break ;
		}
		dt_2.beRepaired(HP_ST - dt_2.getHp());
		if (dt_1.checkDeath() || dt_2.checkDeath()) {
			break ;
		}
	}
	return 0;
}
