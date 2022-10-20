#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	Harl;

	if (ac == 2) {
		std::string	level(av[1]);
		Harl.complain(level);
	}

	return 0;
}
