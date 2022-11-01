#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

public:
	MateriaSource();
	MateriaSource(MateriaSource const &src);
	~MateriaSource();

	MateriaSource &operator=(MateriaSource const &rhs);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);

private:
	AMateria *_materiasLearnt[4];
};

// std::ostream &operator<<(std::ostream &o, MateriaSource const &i);

#endif /* *************************************************** MATERIASOURCE_H */
