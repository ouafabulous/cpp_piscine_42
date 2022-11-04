#include "ShrubberyCreationForm.hpp"

std::string	ShrubberyCreationForm::tree = "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_";
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
	else {
		std::ofstream		ofs((target.getName()+"_shruberry").c_str());
		if (not ofs.good()) {
			throw ErrorWhileCreatingFile();
		}
			ofs << GREEN << tree << RESET << std::endl;
		}
}

Form					*ShrubberyCreationForm::clone() const
{
	Form	*newForm = new ShrubberyCreationForm;
	return (newForm);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
