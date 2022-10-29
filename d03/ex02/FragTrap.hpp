#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

# define HP_FT 100
# define EP_FT 100
# define AD_FT 30

class FragTrap : public ClapTrap
{

	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap( FragTrap const & src );
		~FragTrap();

		FragTrap &		operator=( FragTrap const & rhs );

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		int		checkDeath();

		void	setHp(std::string op, unsigned int amount);

		void	highFivesGuys(void);

};

std::ostream &			operator<<( std::ostream & o, FragTrap const & i );

#endif /* ******************************************************** FRAGTRAP_H */
