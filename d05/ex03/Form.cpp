#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	setSigned(0);
	if (_gradeToSign < 1 || _gradeToExecute < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}


Form::Form( const Form & src ) : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs._signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << YELLOW << "Form info: name(" << i.getName() << "); signed(" << i.getSigned() << "); gradeToSign(" << i.getGradeToSign() << "); gradeToExecute(" << i.getGradeToExecute() << ")" << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign) {
		setSigned(1);
	}
	else {
		throw Bureaucrat::GradeTooLowException();
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void				Form::setSigned(bool signedB)
{
	_signed = signedB;
}

std::string const	&Form::getName() const
{
	return (_name);
}

std::string const	Form::getSigned() const
{
	if (_signed) {
		return ("oui");
	}
	else {
		return ("non");
	}
}

int const			&Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int const			&Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

/* ************************************************************************** */
