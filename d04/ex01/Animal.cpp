#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << GREEN << "Animal's default constructor called" << RESET << std::endl;
	this->_type = "Default";
}

Animal::Animal( const Animal & src )
{
	std::cout << GREEN << "Animal's copy constructor called" << RESET << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << GREEN << "Animal's destructor called" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << GREEN << i.getType() << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Animal::makeSound() const
{
	std::cout << GREEN << "If you don't specify which animal I am, I cannot make any sound" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string				Animal::getType() const
{
	return (this->_type);
}

void					Animal::setType(std::string type)
{
	_type = type;
}

void					Animal::setIdea(std::string idea, unsigned int i)
{
	(void)idea;
	(void)i;
}

std::string				Animal::getIdea(unsigned int i) const
{
	(void)i;
	return (NULL);
}

/* ************************************************************************** */
