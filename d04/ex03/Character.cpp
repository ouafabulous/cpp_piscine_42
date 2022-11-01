#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	_name = "Default";
	for (int i = 0; i != 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(std::string name) //: Character()
{
	for (int i = 0; i != 4; i++)
	{
		_inventory[i] = NULL;
	}
	_name = name;
}

Character::Character(const Character &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i != 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
		}
	}
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		// this->~Character();
		// this->Character(rhs._name);
		_name = rhs._name;
		for (int i = 0; i != 4; i++)
		{
			if (!rhs._inventory[i])
			{
				return *this;
			}
			delete _inventory[i];
			_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Character const &i)
{
	o << "Name = " << i.getName();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria *m)
{
	for (int i = 0; i != 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
}

void		Character::unequip(int idx)
{
	if (idx < 4 and idx >= 0)
	{
		for (int i = 0; i != 4; i++)
		{
			if (i == idx)
			{
				_inventory[i] = NULL;
			}
		}
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (_inventory[idx])
	{
		_inventory[idx]->use(target);
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &Character::getName() const
{
	return (_name);
}

AMateria *Character::getInventory(unsigned int i)
{
	if (!_inventory[i]->getType().compare("ice"))
	{
		return ((Ice *)_inventory[i]);
	}
	else
	{
		return ((Cure *)_inventory[i]);
	}
	return (NULL);
}

/* ************************************************************************** */
