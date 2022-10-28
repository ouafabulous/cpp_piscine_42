#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() : _hp(10), _ep(10), _ad(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_ad = rhs.getAd();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &i)
{
	std::cout << "ClapTrap " << i.getName() << " game summary: HitPoints(" << i.getHp() << "), EnergyPoints(" << i.getEp() << "), AttackDamage(" << i.getAd() << ")." << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int		ClapTrap::checkDeath()
{
	if (!getHp() || !getEp()) {
		std::cout << BLUE << "[GAME OVER]" << std::endl;
		std::cout << "ClapTrap " << getName() << " lost!" << RESET << std::endl;
		return 1;
	}
	return 0;
}

void	ClapTrap::attack(const std::string &target)
{
	ClapTrap	the_target(target);

	setEp("-");
	std::cout << RED << "[ATTAAAAACK!!!]" << std::endl;
	if (_amount < 2) {
		std::cout << "ClapTrap " << _name << " attacks " << the_target.getName() << " , causing " << _amount << " point of damage!" << RESET << std::endl;
	}
	else {
		std::cout << "ClapTrap " << _name << " attacks " << the_target.getName() << " , causing " << _amount << " points of damage!" << RESET << std::endl;
	}
	the_target.takeDamage(_amount);
	if (checkDeath()) {
		return ;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << YELLOW <<"[TAKE DAMAGE]" << std::endl;
	std::cout << "ClapTrap " << getName() << "'s Hit Points before damage: " << getHp() << std::endl;
	std::cout << "ClapTrap " << getName() << "'s Attack Damage before damage: " << getAd() << std::endl;
	setAd("+", amount);
	setHp("-", amount);
	std::cout << "----------" << std::endl;
	std::cout << "ClapTrap " << getName() << "'s Hit points after damage: " << getHp() << std::endl;
	std::cout << "ClapTrap " << getName() << "'s Attack damage after damage: " << getAd() << RESET << std::endl;
	if (checkDeath()) {
		return ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << GREEN << "[BE REPAIRED]" << std::endl;
	std::cout << "ClapTrap " << getName() << "'s Hit Points before being repaired: " << getHp() << std::endl;
	std::cout << "ClapTrap " << getName() << "'s Energy Points before being repaired: " << getEp() << std::endl;
	setEp("-");
	setHp("+", amount);
	std::cout << "----------" << std::endl;
	std::cout << "ClapTrap " << getName() << "'s Hit Points after being repaired: " << getHp() << std::endl;
	std::cout << "ClapTrap " << getName() << "'s Energy Points after being repaired: " << getEp() << RESET << std::endl;
	if (checkDeath()) {
		return ;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName() const
{
	return (_name);
}

void ClapTrap::setName(std::string new_name)
{
	_name = new_name;
}

unsigned int ClapTrap::getHp() const
{
	return (_hp);
}

void ClapTrap::setHp(std::string op, unsigned int amount)
{
	if (!op.compare("-"))
	{
		_hp -= amount;
	}
	else if (!op.compare("+"))
	{
		_hp += amount;
	}
	return;
}

unsigned int ClapTrap::getEp() const
{
	return (_ep);
}

void ClapTrap::setEp(std::string op)
{
	if (!op.compare("-"))
	{
		_ep--;
	}
	else if (!op.compare("+"))
	{
		_ep++;
	}
	return;
}

unsigned int ClapTrap::getAd() const
{
	return (_ad);
}

void ClapTrap::setAd(std::string op, unsigned int amount)
{
	if (!op.compare("-"))
	{
		_ad -= amount;
	}
	else if (!op.compare("+"))
	{
		_ad += amount;
	}
	return;
}

/* ************************************************************************** */
