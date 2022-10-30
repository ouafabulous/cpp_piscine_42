#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal()
{
	std::cout << YELLOW << "Cat's default constructor called" << RESET << std::endl;
	this->_type = "Cat";
	_brain = new Brain;
}

Cat::Cat( const Cat & src ) : Animal(src)
{
	std::cout << YELLOW << "Cat's copy constructor called" << RESET << std::endl;
	_brain = new Brain(*src._brain);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << YELLOW << "Cat's destructor called" << RESET << std::endl;
	delete _brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		Animal::operator=(rhs);
		_brain = new Brain(*rhs._brain);
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

std::string			Cat::getIdea(unsigned int i) const
{
	return (_brain->getIdea(i));
}

void				Cat::setIdea(std::string idea, unsigned int i)
{
	_brain->setIdea(i, idea);
}

/* ************************************************************************** */
