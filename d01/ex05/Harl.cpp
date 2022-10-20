#include "Harl.hpp"

const char *Harl::_level[NUMBER] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl() {
	_tab[0] = &Harl::_debug;
	_tab[1] = &Harl::_info;
	_tab[2] = &Harl::_warning;
	_tab[3] = &Harl::_error;
}

Harl::~Harl() {}

void Harl::_debug(void) const
{
	std::cout << DEBUG_MSG << std::endl;
}

void Harl::_info(void) const
{
	std::cout << INFO_MSG << std::endl;
}

void Harl::_warning(void) const
{
	std::cout << WARNING_MSG << std::endl;
}

void Harl::_error(void) const
{
	std::cout << ERROR_MSG << std::endl;
}

void Harl::complain(std::string level) const
{
	int i;
	i = 0;

	_tab[0] = &Harl::_info;
	while (i < NUMBER)
	{
		if (level.compare(_level[i]))
			((const Harl *))->Harl::_tab[i]();
	}
}
