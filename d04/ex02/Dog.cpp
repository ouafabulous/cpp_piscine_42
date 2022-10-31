#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : AAnimal()
{
	std::cout << MAGENTA << "Dog's default constructor called" << RESET << std::endl;
	this->_type = "Dog";
	_brain = new Brain;
}

Dog::Dog( const Dog & src ) : AAnimal(src)
{
	std::cout << MAGENTA << "Dog's copy constructor called" << RESET << std::endl;
	_brain = new Brain(*src._brain);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << MAGENTA << "Dog's destructor called" << RESET << std::endl;
	delete	_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		AAnimal::operator=(rhs);
		_brain = new Brain(*rhs._brain);
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

std::string			Dog::getIdea(unsigned int i) const
{
	return (_brain->getIdea(i));
}

void				Dog::setIdea(std::string idea, unsigned int i)
{
	_brain->setIdea(i, idea);
}

/* ************************************************************************** */
