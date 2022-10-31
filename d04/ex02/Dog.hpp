#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public virtual AAnimal
{

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog &		operator=( Dog const & rhs );

		std::string		getType() const;

		void			setIdea(std::string idea, unsigned int i);
		std::string		getIdea(unsigned int i) const;

		void			makeSound() const;

	private:

		std::string	_type;
		Brain		*_brain;

};

std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif /* ************************************************************* DOG_H */
