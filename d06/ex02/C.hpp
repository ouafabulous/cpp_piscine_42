#ifndef C_HPP
# define C_HPP

# include <iostream>
# include <string>
# include "Base.hpp"

class C : public Base
{

	public:

		C();
		~C();

		C &		operator=( C const & rhs );

		std::string	getName() const;

	private:

		std::string	_name;

};

std::ostream &			operator<<( std::ostream & o, C const & i );

#endif /* *************************************************************** C_H */