#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

# define SCF_TOSIGN 145
# define SCF_TOEXECUTE 137

# define RRF_TOSIGN 72
# define RRF_TOEXECUTE 45

# define PPF_TOSIGN 25
# define PPF_TOEXECUTE 5

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
		virtual ~Form() = 0;
		class DocumentNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("This document is not signed, hence cannot be executed!");
				}
		};

		Form &				operator=( Form const & rhs );

		void				setSigned(bool signedB);

		std::string const	&getName() const;
		std::string const	getSigned() const;
		int const			&getGradeToSign() const;
		int const			&getGradeToExecute() const;

		virtual void		beSigned(const Bureaucrat &Bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

	private:

		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

};

std::ostream &				operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */
