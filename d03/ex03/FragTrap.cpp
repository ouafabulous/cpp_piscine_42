#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	std::cout << BLUE << "Default constructor called for FragTrap" << RESET << std::endl;
	ClapTrap("Default", 100, 100, 30);
}

FragTrap::FragTrap(std::string name)
{
	std::cout << BLUE << "Name constructor called for FragTrap" << RESET << std::endl;
	ClapTrap(name, 100, 100, 30);
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
		std::cout << BLUE << "Copy constructor called for FragTrap" << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << BLUE << "Destructor called for ScavTrap" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
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

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	std::cout << BLUE << "FragTrap " << i.getName() << " game summary: HitPoints(" << i.getHp() << "), EnergyPoints(" << i.getEp() << "), AttackDamage(" << i.getAd() << ")." << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int		FragTrap::checkDeath()
{
	if (!getHp() || !getEp()) {
		std::cout << BLUE << "[GAME OVER]" << std::endl;
		std::cout << "FragTrap " << getName() << " lost!" << RESET << std::endl;
		return 1;
	}
	return 0;
}

void	FragTrap::attack(const std::string &target)
{
	FragTrap	the_target(target);

	setEp("-");
	std::cout << BLUE << "[ATTAAAAACK!!!]" << std::endl;
	if (_amount < 2) {
		std::cout << "FragTrap " << _name << " attacks " << the_target.getName() << " , causing " << _amount << " point of damage!" << RESET << std::endl;
	}
	else {
		std::cout << "FragTrap " << _name << " attacks " << the_target.getName() << " , causing " << _amount << " points of damage!" << RESET << std::endl;
	}
	the_target.takeDamage(_amount);
	if (checkDeath()) {
		return ;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << BLUE <<"[TAKE DAMAGE]" << std::endl;
	std::cout << "FragTrap " << getName() << "'s Hit Points before damage: " << getHp() << std::endl;
	std::cout << "FragTrap " << getName() << "'s Attack Damage before damage: " << getAd() << std::endl;
	setAd("+", amount);
	setHp("-", amount);
	std::cout << "----------" << std::endl;
	std::cout << "FragTrap " << getName() << "'s Hit points after damage: " << getHp() << std::endl;
	std::cout << "FragTrap " << getName() << "'s Attack damage after damage: " << getAd() << RESET << std::endl;
	if (checkDeath()) {
		return ;
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << BLUE << "[BE REPAIRED]" << std::endl;
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

void	FragTrap::highFivesGuys()
{
	std::cout << BLUE << "🙌" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
