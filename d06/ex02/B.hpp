#ifndef B_HPP
# define B_HPP

# include <iostream>
# include <string>
# include "Base.hpp"

class B : public Base
{

	public:

		B();
		~B();

		std::string	getName() const;

	private:

		std::string	_name;

};

std::ostream &			operator<<( std::ostream & o, B const & i );

#endif /* *************************************************************** B_H */