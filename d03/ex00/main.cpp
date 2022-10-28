#include "ClapTrap.hpp"

int main()
{
	ClapTrap			ct_1("Amoeba");
	const std::string	&opponent = "Tiger";

	ct_1.attack(opponent);

	return 0;
}

