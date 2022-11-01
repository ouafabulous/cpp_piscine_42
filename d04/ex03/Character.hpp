#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include <typeinfo>

class Character : public ICharacter
{

	public:

		Character();
		Character(std::string name);
		Character( Character const & src );
		~Character();

		Character &			operator=( Character const & rhs );

		std::string const	&getName() const;
		AMateria			*getInventory(unsigned int i);

		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	private:

		AMateria			*_inventory[4];
		std::string			_name;

};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */
