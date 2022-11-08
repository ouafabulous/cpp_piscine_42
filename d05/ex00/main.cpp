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
			Bureaucrat bob("bob", 14);
			Bureaucrat paula(bob);
			std::cout << paula;
			paula.incrementGrade();
			std::cout << "-----------" << std::endl;
			std::cout << paula;
			Bureaucrat loser("loser", 150);
			std::cout << loser;
			loser.decrementGrade();
			std::cout << "-----------" << std::endl;
			std::cout << loser;
		}
		catch (const std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	return 0;
}
