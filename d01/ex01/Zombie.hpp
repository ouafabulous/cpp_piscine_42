#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {

public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void		announce(void) const;
	std::string	getName(void) const;
	void		setName(std::string name_horde);

private:

	std::string	_name;

};

Zombie*	zombieHorde(int N, std::string name);

#endif
