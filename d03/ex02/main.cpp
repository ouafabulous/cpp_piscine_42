#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap	st_1("Amoeba");
	ClapTrap	ct_1("Clappinette");
	FragTrap	ft_1("Charles");
	FragTrap	ft_2("Charles");

	st_1.guardGate();
	ft_1.highFivesGuys();

	// while (1)
	// {
	// 	ct_1.attack(ft_2.getName());
	// 	if (ct_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ft_2.takeDamage(ct_1.getAd());
	// 	if (ct_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ft_2.attack(ct_1.getName());
	// 	if (ct_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ct_1.takeDamage(ft_2.getAd());
	// 	if (ct_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// }

	while (1)
	{
		ft_1.attack(st_1.getName());
		if (ft_1.checkDeath() || st_1.checkDeath()) {
			break ;
		}
		st_1.takeDamage(ft_1.getAd());
		if (ft_1.checkDeath() || st_1.checkDeath()) {
			break ;
		}
		st_1.attack(ft_1.getName());
		if (ft_1.checkDeath() || st_1.checkDeath()) {
			break ;
		}
		ft_1.takeDamage(st_1.getAd());
		if (ft_1.checkDeath() || st_1.checkDeath()) {
			break ;
		}
	}

	// while (1)
	// {
	// 	ft_1.attack(ft_2.getName());
	// 	if (ft_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ft_2.takeDamage(ft_1.getAd());
	// 	if (ft_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ft_1.beRepaired(HP_ST - ft_1.getHp());
	// 	if (ft_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ft_2.attack(ft_1.getName());	// 	st_1.takeDamage(st_2.getAd());
	// 	if (ft_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ft_1.takeDamage(ft_2.getAd());
	// 	if (ft_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// 	ft_2.beRepaired(HP_ST - ft_2.getHp());
	// 	if (ft_1.checkDeath() || ft_2.checkDeath()) {
	// 		break ;
	// 	}
	// }
	return 0;
}
