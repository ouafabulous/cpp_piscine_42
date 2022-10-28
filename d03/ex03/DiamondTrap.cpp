#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name+"_clap_name", 42, 42, 42), ScavTrap(), FragTrap()
{
	_name = name;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		FragTrap::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	std::cout << BLUE << "DiamondTrap " << i.getName() << " game summary: HitPoints(" << i.getHp() << "), EnergyPoints(" << i.getEp() << "), AttackDamage(" << i.getAd() << ")." << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
