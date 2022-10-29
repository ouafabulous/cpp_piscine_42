#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name", HP_FT, EP_ST, AD_FT), ScavTrap(), FragTrap()
{
	std::cout << RED << "DiamondTrap default constructor called" << RESET << std::endl;
	_name = "Default";
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name+"_clap_name", HP_FT, EP_ST, AD_FT), ScavTrap(), FragTrap()
{
	std::cout << RED << "DiamondTrap name constructor called" << RESET << std::endl;
	this->_name = name;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << RED << "DiamondTrap copy constructor called" << RESET << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap destructor called" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		ClapTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		ScavTrap::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	std::cout << RED << "DiamondTrap " << i.getName() << " game summary: HitPoints(" << i.getHp() << "), EnergyPoints(" << i.getEp() << "), AttackDamage(" << i.getAd() << ")." << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	std::cout << RED <<"[TAKE DAMAGE 🤕🤕🤕]" << std::endl;
	std::cout << "DiamondTrap " << _name << "'s Hit Points before damage: " << getHp() << std::endl;
	setHp("-", amount);
	std::cout << "----------" << std::endl;
	std::cout << "DiamondTrap " << _name << "'s Hit points after damage: " << getHp() << RESET << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	std::cout << RED << "[BE REPAIRED ❤️‍🩹❤️‍🩹❤️‍🩹]" << std::endl;
	std::cout << "DiamondTrap " << _name << "'s Hit Points before being repaired: " << getHp() << std::endl;
	std::cout << "DiamondTrap " << _name << "'s Energy Points before being repaired: " << getEp() << std::endl;
	setEp("-");
	setHp("+", amount);
	std::cout << "----------" << std::endl;
	std::cout << "DiamondTrap " << _name << "'s Hit Points after being repaired: " << getHp() << std::endl;
	std::cout << "DiamondTrap " << _name << "'s Energy Points after being repaired: " << getEp() << RESET << std::endl;
}


void	DiamondTrap::whoAmI()
{
	std::cout << RED << "My name is: " << _name << " and my ClapTrap name is: " << ClapTrap::_name  << " 💎💎💎"<< RESET << std::endl;
}

int		DiamondTrap::checkDeath()
{
	if (!getHp() || !getEp()) {
		std::cout << RED << "[GAME OVER 💀💀💀]" << std::endl;
		std::cout << "DiamondTrap " << _name << " lost!" << RESET << std::endl;
		return 1;
	}
	return 0;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	DiamondTrap::setHp(std::string op, unsigned int amount)
{
	FragTrap::setHp(op, amount);
}

/* ************************************************************************** */
