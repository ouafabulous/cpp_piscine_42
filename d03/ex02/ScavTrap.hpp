#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

# define HP_ST 100
# define EP_ST 50
# define AD_ST 20

class ScavTrap : public
ClapTrap
{

	public:

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		int		checkDeath();

		void	setHp(std::string op, unsigned int amount);

		void	guardGate();

};

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i );

#endif /* ******************************************************** SCAVTRAP_H */
