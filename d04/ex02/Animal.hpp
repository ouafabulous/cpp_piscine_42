#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define YELLOW  "\033[1m\033[33m"
# define MAGENTA "\033[1m\033[35m"
# define BLUE    "\033[1m\033[34m"
# define RED     "\033[1m\033[31m"
# define RESET   "\033[0m"
# define GREEN   "\033[1m\033[32m"
# define YELLOW_NEG "\033[33;7"

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		Animal &				operator=( Animal const & rhs );

		virtual std::string		getType() const = 0;
		void					setType(std::string type);

		virtual void			makeSound() const;

		void			setIdea(std::string idea, unsigned int i);
		virtual std::string		getIdea(unsigned int i) const;

	protected:

		std::string		_type;

};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif /* ********************************************************** ANIMAL_H */
