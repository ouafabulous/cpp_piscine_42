// #include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <memory>

int main()
{
	// AMateria *ice = new Ice;
	// AMateria *cure = new Cure;
	Character *test = new Character();
	// Character *test1 = new Character();
	AMateria *icinette = new Ice();

	// test->operator=(*test1);
	test->getName();
	test->equip(icinette);
	std::cout << test->getInventory(0)->getType() << std::endl;

	delete test;
	// delete test1;

	// on met du code qui peut renvoyer une exception...

	return 0;
}
