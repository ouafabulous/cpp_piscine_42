#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
{
	setName("Default");
	setGrade(150);
}

Bureaucrat::Bureaucrat(int grade)
{
	setName("Default");
	setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name)
{
	setName(name);
	setGrade(150);
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	setName(name);
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << GREEN << i.getName() << " has grade " << i.getGrade() << RESET << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade()
{
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	setGrade(_grade + 1);
}

void		Bureaucrat::signForm(Form &form)
{
try
{
	form.beSigned(*this);
	std::cout << getName() << " signed " << form.getName() << std::endl;
}
catch(const std::exception& e)
{
	std::cout << getName() << " couldn't signed " << form.getName() << " because " << e.what() << std::endl;
}

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::setName(std::string name)
{
	_name = name;
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooHighException();
	}
	else
	{
		_grade = grade;
	}
}

/* ************************************************************************** */
