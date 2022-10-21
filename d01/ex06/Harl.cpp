#include "Harl.hpp"

const char *Harl::_level[NUMBER] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl() {
	_tab[DEBUG] = &Harl::_debug;
	_tab[INFO] = &Harl::_info;
	_tab[WARNING] = &Harl::_warning;
	_tab[ERROR] = &Harl::_error;
}

Harl::~Harl() {}

void Harl::_debug(void) const
{
	std::cout << YELLOW << DEBUG_MSG << RESET << std::endl;
}

void Harl::_info(void) const
{
	std::cout << MAGENTA << INFO_MSG << RESET << std::endl;
}

void Harl::_warning(void) const
{
	std::cout << BLUE << WARNING_MSG << RESET << std::endl;
}

void Harl::_error(void) const
{
	std::cout << RED << ERROR_MSG << RESET << std::endl;
}

void Harl::complain(std::string level) const
{
	int i;
	i = 0;

	while (i < NUMBER)
	{
		if (!level.compare(_level[i])) {
			switch(i) {
				case DEBUG:
				{
					Func func = _tab[DEBUG];
					(this->*func)();
					std::cout << std::endl;
					__attribute__((fallthrough));
				}
				case INFO:
				{
					Func func = _tab[INFO];
					(this->*func)();
					std::cout << std::endl;
					__attribute__((fallthrough));
				}
				case WARNING:
				{
					Func func = _tab[WARNING];
					(this->*func)();
					std::cout << std::endl;
					__attribute__((fallthrough));
				}
				case ERROR:
				{
					Func func = _tab[ERROR];
					(this->*func)();
					return ;
				}
			}
		}
		i++;
	}
	std::cout << GREEN << OTHER_MSG << RESET << std::endl;
}
