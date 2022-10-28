#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define YELLOW  "\033[1m\033[33m"
# define MAGENTA "\033[1m\033[35m"
# define BLUE    "\033[1m\033[34m"
# define RED     "\033[1m\033[31m"
# define RESET   "\033[0m"
# define GREEN   "\033[1m\033[32m"

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
		virtual int		checkDeath();


		std::string		getName() const;
		void			setName(std::string new_name);

		unsigned int	getHp() const;
		void			setHp(std::string op, unsigned int amount);

		unsigned int	getEp() const;
		void			setEp(std::string op);

		unsigned int	getAd() const;
		void			setAd(std::string op, unsigned int amount);

	protected:

		std::string					_name;
		unsigned int				_hp;
		unsigned int				_ep;
		unsigned int				_ad;
		static const unsigned int	_amount = 10;

};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i);

#endif /* ******************************************************** CLAPTRAP_H */
