#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

class RobotomyRequestForm : public Form
{

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	void execute(Bureaucrat const &executor) const;

private:

	std::string			_target;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);

#endif /* ******************************************* RobotomyRequestForm_H */
