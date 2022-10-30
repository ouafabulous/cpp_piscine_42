#ifndef WORNGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define YELLOW  "\033[1m\033[33m"
# define MAGENTA "\033[1m\033[35m"
# define BLUE    "\033[1m\033[34m"
# define RED     "\033[1m\033[31m"
# define RESET   "\033[0m"
# define GREEN   "\033[1m\033[32m"
# define YELLOW_NEG "\033[33;7"

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();

		WrongAnimal &				operator=( WrongAnimal const & rhs );

		std::string				getType() const;
		void					setType(std::string type);

		void					makeSound() const;

	protected:

		std::string		_type;

};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

#endif /* ********************************************************** ANIMAL_H */
