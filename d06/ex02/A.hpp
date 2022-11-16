#ifndef A_HPP
# define A_HPP

# include <iostream>
# include <string>
# include "Base.hpp"

class A : public Base
{

	public:

		A();
		~A();

		std::string	getName() const;

	private:

		std::string	_name;

};

std::ostream &			operator<<( std::ostream & o, A const & i );

#endif /* *************************************************************** A_H */