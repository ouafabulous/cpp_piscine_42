#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal()
{
	std::cout << MAGENTA << "Dog's default constructor called" << RESET << std::endl;
	this->_type = "Dog";
}

Dog::Dog( const Dog & src ) : Animal(src)
{
	std::cout << MAGENTA << "Dog's copy constructor called" << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << MAGENTA << "Dog's destructor called" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		Animal::operator=(rhs);
	}
	return *this;
}

std::ostream &		operator<<( std::ostream & o, Dog const & i )
{
	o << MAGENTA << i.getType() << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Dog::makeSound() const
{
	std::cout << MAGENTA << "Woof Woof!! 🐶🐶🐶" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string			Dog::getType() const
{
	return (this->_type);
}

/* ************************************************************************** */
