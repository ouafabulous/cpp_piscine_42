#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

# include <iostream>
# include <string>

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap
{

	public:

		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();

		DiamondTrap &		operator=( DiamondTrap const & rhs );

		void				attack(const std::string& target);
		int					checkDeath();
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		void				whoAmI();

		void				setHp(std::string op, unsigned int amount);

	private:

		std::string			_name;

};

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i );

#endif /* ***************************************************** DIAMONDTRAP_H */
