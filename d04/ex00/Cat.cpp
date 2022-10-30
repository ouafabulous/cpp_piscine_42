#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal()
{
	std::cout << YELLOW << "Cat's default constructor called" << RESET << std::endl;
	this->_type = "Cat";
}

Cat::Cat( const Cat & src ) : Animal(src)
{
	std::cout << YELLOW << "Cat's copy constructor called" << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << YELLOW << "Cat's destructor called" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		Animal::operator=(rhs);
	}
	return *this;
}

std::ostream &		operator<<( std::ostream & o, Cat const & i )
{
	o << YELLOW << i.getType() << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Cat::makeSound() const
{
	std::cout << YELLOW << "MeooooooowWww!! 😸😸😸" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string			Cat::getType() const
{
	return (this->_type);
}

/* ************************************************************************** */
