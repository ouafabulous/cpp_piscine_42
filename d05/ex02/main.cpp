#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
		try
	{
		Bureaucrat bob(180);
		std::cout << bob;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		try
		{
			ShrubberyCreationForm scf;
			RobotomyRequestForm	rrf;
			PresidentialPardonForm ppf;
			Bureaucrat sm("Superior_max", 1);
			Bureaucrat s("Superior", 70);
			Bureaucrat l("Loser");
			std::cout << l;
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
	}
	return 0;
}
