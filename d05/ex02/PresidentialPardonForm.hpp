#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public Form
{

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	void execute(Bureaucrat const &executor) const;

private:

	std::string				_target;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);

#endif /* ******************************************* PresidentialPardonForm_H */
