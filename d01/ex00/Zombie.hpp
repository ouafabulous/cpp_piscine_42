#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"

class Zombie {

public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void		announce(void) const;
	std::string	getName(void) const;
	void		setName(std::string name);

private:

	std::string	_name;

};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
