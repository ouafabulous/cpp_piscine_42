#include "Ice.hpp"
#include "Cure.hpp"
#include <memory>

int main()
{
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	std::cout << *cure << '\n';


	// on met du code qui peut renvoyer une exception...

	return 0;
}
