#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "Ice.hpp"

class Ice : public AMateria
{

	public:

		Ice();
		Ice( Ice const & src );
		~Ice();

		Ice&		operator=( Ice const & rhs );

		AMateria*	clone() const;
		void		use(ICharacter &target);

	private:



};

std::ostream &			operator<<( std::ostream & o, Ice const & i );

#endif /* ************************************************************* ICE_H */
