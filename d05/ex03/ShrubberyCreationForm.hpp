#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm( const ShrubberyCreationForm & src );
		~ShrubberyCreationForm();

		class ErrorWhileCreatingFile : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error while creating file.");
				}
		};

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs);

		void		execute(Bureaucrat const & executor) const;

	private:

		static std::string	tree;

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */
