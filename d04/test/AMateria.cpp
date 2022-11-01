#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : _type("Default")
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria( const AMateria & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AMateria const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const		&AMateria::getType() const
{
	return (_type);
}

/* ************************************************************************** */
