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

# define HP_CT 10
# define EP_CT 10
# define AD_CT 10

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		int				checkDeath();


		std::string		getName() const;
		void			setName(std::string new_name);

		unsigned int	getHp() const;
		void			setHp(std::string op, unsigned int amount);

		unsigned int	getEp() const;
		void			setEp(std::string op);

		unsigned int	getAd() const;
		void			setAd(std::string op, unsigned int amount);

	private:

		std::string					_name;
		unsigned int				_hp;
		unsigned int				_ep;
		unsigned int				_ad;

};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i);

#endif /* ******************************************************** CLAPTRAP_H */
