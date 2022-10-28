#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// ClapTrap			ct_1("Amoeba");
	// ScavTrap			st_1("Lolo");
	// FragTrap			ft_1("Mimi");
	DiamondTrap			dt_1("Diamond");

	const std::string	&opponent = "Tiger";

	// ct_1.attack(opponent);
	// st_1.attack(opponent);
	std::cout << dt_1.getName() << " " << dt_1.getHp()<< " " << dt_1.getEp() << " " << dt_1.getAd() << std::endl;

	return 0;
}

