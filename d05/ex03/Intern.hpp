#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();
		class ErrorFormName : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Invalid form name.");
				}
		};

		Intern &		operator=( Intern const & rhs );

		Form			*makeForm(std::string nameForm, std::string target);

		void			learnForm(Form *f);
		Form			*createForm(std::string const & type);

	private:
		Form			*_formsLearnt[3];

	private:



};

#endif /* ********************************************************** INTERN_H */
