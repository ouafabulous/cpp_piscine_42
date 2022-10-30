#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );

		std::string	getIdea(unsigned int i) const;
		void		setIdea(unsigned int i, std::string idea);

	private:

		std::string	_ideas[100];

};

std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* *********************************************************** BRAIN_H */
