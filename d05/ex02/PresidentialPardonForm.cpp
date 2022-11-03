#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", PPF_TOSIGN, PPF_TOEXECUTE)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form("PresidentialPardonForm", PPF_TOSIGN, PPF_TOEXECUTE)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	Form::operator=(rhs);
	return *this;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i)
{
	o << YELLOW << "Form info: name("
	  << i.getName() << "); signed(" << i.getSigned() << "); gradeToSign(" << i.getGradeToSign() << "); gradeToExecute(" << i.getGradeToExecute() << ")" << RESET << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute(const Bureaucrat &target) const
{
	if (this->getSigned().compare("oui"))
	{
		throw DocumentNotSigned();
	}
	else if (getGradeToExecute() < target.getGrade())
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
