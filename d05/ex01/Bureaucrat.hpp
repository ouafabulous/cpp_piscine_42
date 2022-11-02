#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

# define GREEN   "\033[1m\033[32m"
# define RED     "\033[1m\033[31m"
# define RESET   "\033[0m"

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();
		class GradeTooHighException : public std::exception //exception?
		{
			public:
				virtual const char* what() const throw()
				{
					return ("This grade is too high. It will be set arbitrarily to 0.\nReminder: Grade should range between 1 and 150.");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("This grade is too low. It will be set arbitrarily to 0.\nReminder: Grade should range between 1 and 150.");
				}
		};

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string const	&getName() const;
		int					getGrade() const;
		void				setName(std::string name);
		void				setGrade(int grade);

		void				incrementGrade();
		void				decrementGrade();

		void				signForm(Form &form);

	private:

		std::string			_name;
		int					_grade;

};

std::ostream &				operator<<( std::ostream & o, Bureaucrat const & i);

#endif /* ****************************************************** BUREAUCRAT_H */
