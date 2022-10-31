#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal()
{
	std::cout << GREEN << "AAnimal's default constructor called" << RESET << std::endl;
	this->_type = "Default";
}

AAnimal::AAnimal( const AAnimal & src )
{
	std::cout << GREEN << "AAnimal's copy constructor called" << RESET << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << GREEN << "AAnimal's destructor called" << RESET << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i )
{
	o << GREEN << i.getType() << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				AAnimal::makeSound() const
{
	std::cout << GREEN << "If you don't specify which animal I am, I cannot make any sound" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void					AAnimal::setType(std::string type)
{
	_type = type;
}

void					AAnimal::setIdea(std::string idea, unsigned int i)
{
	(void)idea;
	(void)i;
}

std::string				AAnimal::getIdea(unsigned int i) const
{
	(void)i;
	return (NULL);
}

/* ************************************************************************** */
