#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap("Default", HP_ST, EP_ST, AD_ST)
{
	std::cout << YELLOW << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, HP_ST, EP_ST, AD_ST)
{
	std::cout << YELLOW << "ScavTrap name constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap()
{
	std::cout << YELLOW << "ScavTrap copy constructor called" << RESET << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "ScavTrap destructor called" << RESET << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	if ( this != &rhs )
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
{
	std::cout << YELLOW << "ScavTrap " << i.getName() << " game summary: HitPoints(" << i.getHp() << "), EnergyPoints(" << i.getEp() << "), AttackDamage(" << i.getAd() << ")." << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int		ScavTrap::checkDeath()
{
	if (!getHp() || !getEp()) {
		std::cout << YELLOW << "[GAME OVER 💀💀💀]" << std::endl;
		std::cout << "ScavTrap " << getName() << " lost!" << RESET << std::endl;
		return 1;
	}
	return 0;
}

void	ScavTrap::attack(const std::string &target)
{
	setEp("-");
	std::cout << YELLOW << "[ATTAAAAACK!!! 💥💥💥]" << std::endl;
	if (getAd() < 2) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << getAd() << " point of damage!" << RESET << std::endl;
	}
	else {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << getAd() << " points of damage!" << RESET << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << YELLOW << "ScavTrap is now in gatekeeper mode 🔓🔓🔓" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void ScavTrap::setHp(std::string op, unsigned int amount)
{
	if (!op.compare("-"))
	{
		if (amount > getHp()) {
			_hp = 0;
			return ;
		}
		_hp -= amount;
	}
	else if (!op.compare("+"))
	{
		if (_hp < HP_ST) {
			_hp += amount;
		}
	}
	return;
}

/* ************************************************************************** */
