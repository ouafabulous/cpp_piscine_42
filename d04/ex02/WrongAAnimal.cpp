#include "WrongAAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAAnimal::WrongAAnimal()
{
	std::cout << GREEN << "WrongAAnimal's default constructor called" << RESET << std::endl;
	this->_type = "Default";
}

WrongAAnimal::WrongAAnimal( const WrongAAnimal & src )
{
	std::cout << GREEN << "WrongAAnimal's copy constructor called" << RESET << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAAnimal::~WrongAAnimal()
{
	std::cout << GREEN << "WrongAAnimal's destructor called" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAAnimal &				WrongAAnimal::operator=( WrongAAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAAnimal const & i )
{
	o << GREEN << i.getType() << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				WrongAAnimal::makeSound() const
{
	std::cout << GREEN << "If you don't specify which animal I am, I cannot make any sound" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string				WrongAAnimal::getType() const
{
	return (this->_type);
}

void					WrongAAnimal::setType(std::string type)
{
	_type = type;
}

/* ************************************************************************** */
