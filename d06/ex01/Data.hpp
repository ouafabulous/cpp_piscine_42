#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <stdint.h>

class Data
{

	public:

		Data();
		Data( Data const & src );
		~Data();

		Data &		operator=( Data const & rhs );

		int			getValue() const;
		std::string	getName() const;

	private:

		int			_value;
		std::string	_name;

};

std::ostream &			operator<<( std::ostream & o, Data const & i );

uintptr_t   serialize(Data* ptr) ;
Data	    *deserialize(uintptr_t raw);

#endif /* ************************************************************ DATA_H */