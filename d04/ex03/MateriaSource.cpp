#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for(int i = 0; i != 4; i++)
	{
		_materiasLearnt[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i != 4; i++)
	{
		if (_materiasLearnt[i]) {
			delete _materiasLearnt[i];
		}
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i != 4; i++) {
			if (_materiasLearnt[i]) {
				delete _materiasLearnt[i];
				_materiasLearnt[i] = rhs._materiasLearnt[i];
			}
		}
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, MateriaSource const & i )
// {
	// o << "Value = " << ;
	// return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void				MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i != 4; i++)
	{
		if (!_materiasLearnt[i] && m) {
			_materiasLearnt[i] = m->clone();
			delete m;
			return ;
		}
	}
}

AMateria*			MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i != 4; i++)
	{
		if (_materiasLearnt[i] and !_materiasLearnt[i]->getType().compare(type)) {
			return _materiasLearnt[i]->clone();
		}
	}
	return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
