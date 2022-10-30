#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal's default constructor called" << RESET << std::endl;
	this->_type = "Default";
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	std::cout << GREEN << "WrongAnimal's copy constructor called" << RESET << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal's destructor called" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i )
{
	o << GREEN << i.getType() << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				WrongAnimal::makeSound() const
{
	std::cout << GREEN << "If you don't specify which animal I am, I cannot make any sound" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string				WrongAnimal::getType() const
{
	return (this->_type);
}

void					WrongAnimal::setType(std::string type)
{
	_type = type;
}

/* ************************************************************************** */
