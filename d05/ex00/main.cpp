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
			Bureaucrat bob;
			bob.setName("Bob");
			bob.setGrade(14);
			std::cout << bob;
		}
		catch (const std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	return 0;
}
