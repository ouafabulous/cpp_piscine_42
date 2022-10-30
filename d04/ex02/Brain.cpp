#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << BLUE << "Brain's default constructor called" << std::endl;
}

Brain::Brain( const Brain & src )
{
	*this = src;
	int	i = 0;
	while (i < 100)
	{
		_ideas[i] = src._ideas[i];
		i++;
	}
	std::cout << BLUE << "Brain's copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << BLUE << "Brain's destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		int	i = 0;
		while  (i < 100)
		{
			this->_ideas[i] = rhs._ideas[i];
			i++;
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & i )
{
	int	j = 0;
	while (j < 100) {
		o << "Idea " << j << " is: " << i.getIdea(j) << std::endl;
		j++;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Brain::setIdea(unsigned int i, std::string idea)
{
	if (i < 100)
	{
		_ideas[i] = idea;
		return ;
	}
	std::cout << "Error in Brain::setIdea: index i should range between 0 and 100!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Brain::getIdea(unsigned int i) const
{
	if (i < 100)
	{
		return	_ideas[i];
	}
	std::cout << "Error in Brain::getIdea: index i should range between 0 and 100!" << std::endl;
	return (NULL);
}

/* ************************************************************************** */
