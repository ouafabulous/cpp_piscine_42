#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		ShrubberyCreationForm scf;
		RobotomyRequestForm rrf;
		PresidentialPardonForm ppf;
		Bureaucrat sm("Superior_max", 1);
		Bureaucrat s("Superior", 70);
		Bureaucrat l("Loser");
		Intern		tiffany;

		std::cout << l;
		tiffany.learnForm(&scf);
		tiffany.learnForm(&rrf);
		tiffany.learnForm(&ppf);
		l.signForm(ppf);
		sm.signForm(scf);
		sm.signForm(rrf);

		std::cout << "---------------" << std::endl;
		sm.executeForm(ppf);
		sm.executeForm(scf);
		sm.executeForm(rrf);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return 0;
}
