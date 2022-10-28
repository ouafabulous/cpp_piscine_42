#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap			ct_1("Amoeba");
	ScavTrap			st_1("Lolo");
	FragTrap			ft_1("Mimi");

	const std::string	&opponent = "Tiger";

	ct_1.attack(opponent);
	st_1.attack(opponent);

	return 0;
}

