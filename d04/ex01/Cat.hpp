#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public virtual Animal
{

	public:

		Cat();
		Cat( Cat const & src );
		~Cat();

		Cat &			operator=( Cat const & rhs );

		std::string		getType() const;

		void			setIdea(std::string idea, unsigned int i);
		std::string		getIdea(unsigned int i) const;

		void			makeSound() const;

	private:

		std::string		_type;
		Brain			*_brain;

};

std::ostream &			operator<<( std::ostream & o, Cat const & i );

#endif /* ************************************************************* CAT_H */
