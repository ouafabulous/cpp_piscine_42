#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bob(180);
		std::cout << bob;
	}
	catch (const std::exception &e)
	{
		std::cout << RED<< e.what() << RESET << std::endl;
		try
		{
			Form		form("Visa", -2, 20);
		}
		catch (const std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			try {
				Bureaucrat	bob;
				Form		form("visa", 15, 120);
				bob.setName("Bob");
				bob.setGrade(14);
				std::cout << bob;
				std::cout << form;
				bob.signForm(form);
				std::cout << form;
			}
			catch(const std::exception &e) {
				std::cout << RED << e.what() << RESET << std::endl;
			}
		}
	}
	return 0;
}
