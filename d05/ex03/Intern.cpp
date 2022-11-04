#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	for(int i = 0; i != 3; i++)
	{
		_formsLearnt[i] = NULL;
	}
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	for (int i = 0; i != 3; i++)
	{
		if (_formsLearnt[i]) {
			delete _formsLearnt[i];
		}
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i != 3; i++) {
			if (_formsLearnt[i]) {
				delete _formsLearnt[i];
				_formsLearnt[i] = rhs._formsLearnt[i];
			}
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void				Intern::learnForm(Form* m)
{
	for (int i = 0; i != 3; i++)
	{
		if (!_formsLearnt[i] && m) {
			_formsLearnt[i] = m->clone();
			delete m;
			return ;
		}
	}
}

Form*				Intern::createForm(std::string const & nameForm)
{
	for (int i = 0; i != 3; i++)
	{
		if (_formsLearnt[i] and !_formsLearnt[i]->getName().compare(nameForm)) {
			return _formsLearnt[i]->clone();
		}
	}
	return (NULL);
}

Form					*Intern::makeForm(std::string nameForm, std::string target)
{
	Form	*newForm;
	(void)target;

	newForm = createForm(nameForm);
	if (!newForm) {
		throw Intern::ErrorFormName();
	}
	std::cout << "Intern creates " << nameForm << std::endl;
	return (newForm);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
