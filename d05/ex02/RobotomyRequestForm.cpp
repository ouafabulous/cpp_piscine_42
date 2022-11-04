#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", RRF_TOSIGN, RRF_TOEXECUTE)
{
	_target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form("RobotomyRequestForm", RRF_TOSIGN, RRF_TOEXECUTE)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	Form::operator=(rhs);
	return *this;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i)
{
	o << YELLOW << "Form info: name("
	  << i.getName() << "); signed(" << i.getSigned() << "); gradeToSign(" << i.getGradeToSign() << "); gradeToExecute(" << i.getGradeToExecute() << ")" << RESET << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(const Bureaucrat &target) const
{
	Form::execute(target);
	std::cout << YELLOW << "[VROOM VROOM]" << std::endl;
	srand(time(0));
	int random = rand();
	if (random % 2) {
		std::cout << target.getName() << " has been succesfully robotomized." << RESET << std::endl;
	}
	else {
		std::cout << "Robotomisation of " << _target << " failed." << RESET << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
