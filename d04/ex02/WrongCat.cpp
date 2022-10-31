#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() : WrongAAnimal()
{
	std::cout << YELLOW << "WrongCat's default constructor called" << RESET << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAAnimal(src)
{
	std::cout << YELLOW << "WrongCat's copy constructor called" << RESET << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << YELLOW << "WrongCat's destructor called" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		WrongAAnimal::operator=(rhs);
	}
	return *this;
}

std::ostream &		operator<<( std::ostream & o, WrongCat const & i )
{
	o << YELLOW << i.getType() << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				WrongCat::makeSound() const
{
	std::cout << YELLOW << "MeooooooowWww!! 😸😸😸" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string			WrongCat::getType() const
{
	return (this->_type);
}

/* ************************************************************************** */
