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

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	std::cout << YELLOW << "ScavTrap copy constructor called" << RESET << std::endl;
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

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << YELLOW <<"[TAKE DAMAGE 🤕🤕🤕]" << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Hit Points before damage: " << getHp() << std::endl;
	setHp("-", amount);
	std::cout << "----------" << std::endl;
	std::cout << "ScavTrap " << getName() << "'s Hit points after damage: "<< getHp() << RESET << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << YELLOW << "[BE REPAIRED ❤️‍🩹❤️‍🩹❤️‍🩹]" << std::endl;
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
