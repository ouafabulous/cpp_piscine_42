
#include "Intern.hpp"
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
			Intern carla;

			std::cout << l;
			carla.learnForm(&scf);
			Form *new_shrub = NULL;
			new_shrub = carla.createForm("ShrubberyCreationForm");

			std::cout << *new_shrub;
			l.signForm(*new_shrub);
			sm.signForm(*new_shrub);
			std::cout << "---------------" << std::endl;
			sm.executeForm(*new_shrub);
			if (new_shrub) {
				delete new_shrub;
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	return 0;
}
