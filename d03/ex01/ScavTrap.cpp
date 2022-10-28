#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	std::cout << YELLOW << "Default constructor called for ScavTrap" << RESET << std::endl;
	ClapTrap(NULL, 100, 50, 20);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << YELLOW << "Name constructor called for ScavTrap" << RESET << std::endl;
	ClapTrap(name, 100, 50, 20);
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	std::cout << YELLOW << "Copy constructor called for ScavTrap" << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "Destructor called for ScavTrap" << RESET << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_ad = rhs.getAd();
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
		std::cout << YELLOW << "[GAME OVER]" << std::endl;
		std::cout << "ScavTrap " << getName() << " lost!" << RESET << std::endl;
		return 1;
	}
	return 0;
}

void	ScavTrap::attack(const std::string &target)
{
	ClapTrap	the_target(target);

	setEp("-");
	std::cout << YELLOW << "[ATTAAAAACK!!!]" << std::endl;
	if (_amount < 2) {
		std::cout << "ScavTrap " << _name << " attacks " << the_target.getName() << " , causing " << _amount << " point of damage!" << RESET << std::endl;
	}
	else {
		std::cout << "ScavTrap " << _name << " attacks " << the_target.getName() << " , causing " << _amount << " points of damage!" << RESET << std::endl;
	}
	the_target.takeDamage(_amount);
	if (checkDeath()) {
		return ;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << YELLOW <<"[TAKE DAMAGE]" << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Hit Points before damage: " << getHp() << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Attack Damage before damage: " << getAd() << std::endl;
	setAd("+", amount);
	setHp("-", amount);
	std::cout << "----------" << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Hit points after damage: " << getHp() << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Attack damage after damage: " << getAd() << RESET << std::endl;
	if (checkDeath()) {
		return ;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << YELLOW << "[BE REPAIRED]" << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Hit Points before being repaired: " << getHp() << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Energy Points before being repaired: " << getEp() << std::endl;
	setEp("-");
	setHp("+", amount);
	std::cout << "----------" << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Hit Points after being repaired: " << getHp() << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Energy Points after being repaired: " << getEp() << RESET << std::endl;
	if (checkDeath()) {
		return ;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << YELLOW << "ScavTrap is now in gatekeeper mode" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
