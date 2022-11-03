#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Default"), _signed(false), _gradeToSign(0), _gradeToExecute(0)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name)
{
	setSigned(0);
	setGradeToSign(gradeToSign);
	setGradeToExecute(gradeToExecute);
}


Form::Form( const Form & src )
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
		this->_name = rhs._name;
		this->_signed = rhs._signed;
		this->_gradeToSign = rhs._gradeToSign;
		this->_gradeToExecute = rhs._gradeToExecute;
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

void				Form::setName(std::string name)
{
	_name = name;
}

void				Form::setSigned(bool signedB)
{
	_signed = signedB;
}

void				Form::setGradeToSign(int value)
{
		if (value < 1)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		else if (value > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		else
		{
				_gradeToSign = value;
		}
}

void				Form::setGradeToExecute(int value)
{
		if (value < 1)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		else if (value > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		else
		{
				_gradeToExecute = value;
		}
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
