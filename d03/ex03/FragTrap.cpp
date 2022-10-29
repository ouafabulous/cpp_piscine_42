#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap("default", HP_FT, EP_FT, AD_FT)
{
	std::cout << BLUE << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << BLUE << "FragTrap name constructor called" << RESET << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
		std::cout << BLUE << "FragTrap Copy constructor called" << RESET << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << BLUE << "FragTrap Destructor called" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		ClapTrap::operator=(rhs);
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
		std::cout << BLUE << "[GAME OVER 💀💀💀]" << std::endl;
		std::cout << "FragTrap " << getName() << " lost!" << RESET << std::endl;
		return 1;
	}
	return 0;
}

void	FragTrap::attack(const std::string &target)
{
	setEp("-");
	std::cout << BLUE << "[ATTAAAAACK!!! 💥💥💥]" << std::endl;
	if (getAd() < 2) {
		std::cout << "FragTrap " << _name << " attacks " << target << " , causing " << getAd() << " point of damage!" << RESET << std::endl;
	}
	else {
		std::cout << "FragTrap " << _name << " attacks " << target << " , causing " << getAd() << " points of damage!" << RESET << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << BLUE <<"[TAKE DAMAGE 🤕🤕🤕]" << std::endl;
	std::cout << "FragTrap " << getName() << "'s Hit Points before damage: " << getHp() << std::endl;
	setHp("-", amount);
	std::cout << "----------" << std::endl;
	std::cout << "FragTrap " << getName() << "'s Hit points after damage: " << getHp() << RESET << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << BLUE << "[BE REPAIRED ❤️‍🩹❤️‍🩹❤️‍🩹]" << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Hit Points before being repaired: " << getHp() << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Energy Points before being repaired: " << getEp() << std::endl;
	setEp("-");
	setHp("+", amount);
	std::cout << "----------" << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Hit Points after being repaired: " << getHp() << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Energy Points after being repaired: " << getEp() << RESET << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << BLUE << "FragTrap High Five guys!! 🙌🙌🙌" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void FragTrap::setHp(std::string op, unsigned int amount)
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
		if (_hp < HP_FT) {
			_hp += amount;
		}
	}
	return;
}


/* ************************************************************************** */
