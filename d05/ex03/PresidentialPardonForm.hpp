#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public Form
{

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm();

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

	Form					*clone() const;

	void execute(Bureaucrat const &executor) const;


private:
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);

#endif /* ******************************************* PresidentialPardonForm_H */
