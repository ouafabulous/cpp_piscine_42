#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	// try
	// {
	// 	Bureaucrat bob(180);
	// 	std::cout << bob;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cout << RED << e.what() << RESET << std::endl;
	// 	try
	// 	{
	// 		ShrubberyCreationForm form_test;
	// 		Bureaucrat bob;
	// 		bob.setName("Bob");
	// 		bob.setGrade(14);
	// 		std::cout << bob;
	// 		std::cout << form_test;
	// 		bob.executeForm(form_test);
	// 		std::cout << form_test;
	// 	}
	// 	catch (const std::exception &e)
	// 	{
	// 		std::cout << RED << e.what() << RESET << std::endl;
	// 	}
	// }

		try
	{
		Bureaucrat bob(180);
		std::cout << bob;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		try
		{
			ShrubberyCreationForm form_test;
			Bureaucrat bob("bob", 1);
			std::cout << bob;
			std::cout << form_test;
			bob.signForm(form_test);
			std::cout << form_test;
			bob.executeForm(form_test);
		}
		catch (const std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	return 0;
}
