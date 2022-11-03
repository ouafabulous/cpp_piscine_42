#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", SCF_TOSIGN, SCF_TOEXECUTE)
{
}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : Form("ShrubberyCreationForm", SCF_TOSIGN, SCF_TOEXECUTE)
{
	*this = src;
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	Form::operator=(rhs);
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
		o << YELLOW << "Form info: name(" << i.getName() << "); signed(" << i.getSigned() << "); gradeToSign(" << i.getGradeToSign() << "); gradeToExecute(" << i.getGradeToExecute() << ")" << RESET << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void					ShrubberyCreationForm::execute(const Bureaucrat &target) const
{
	if (this->getSigned().compare("oui")) {
		throw DocumentNotSigned();
	}
	else if (getGradeToExecute() < target.getGrade()) {
		throw Bureaucrat::GradeTooLowException();
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
