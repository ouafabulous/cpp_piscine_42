#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

enum {
	TOSIGN,
	TOEXECUTE
};

class Bureaucrat;

class Form
{

	public:

		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form( Form const & src );
		~Form();

		Form &				operator=( Form const & rhs );

		void				setName(std::string name);
		void				setSigned(bool signedB);
		void				setGradeTool(int grade);
		void				setGradeToSign(int grade);
		void				setGradeToExecute(int grade);

		std::string const	&getName() const;
		std::string const	getSigned() const;
		int const			&getGradeToSign() const;
		int const			&getGradeToExecute() const;

		void				beSigned(const Bureaucrat &Bureaucrat);

	private:

		std::string			_name;
		bool				_signed;
		int					_gradeToSign;
		int					_gradeToExecute;

};

std::ostream &				operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */
