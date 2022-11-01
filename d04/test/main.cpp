#include "Ice.hpp"
#include "Cure.hpp"
#include <memory>
# include <typeinfo>

int main()
{


	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	const std::type_info& r1 = typeid(cure);
	const std::type_info& r2 = typeid(ice);

	// std::cout << "Cure: " << r1.name() << std::endl;
	// std::cout << "Ice: " << r2.name() << std::endl;
	if (instanceof(cure)==typeid(cure)) {
	// 	std::cout << "yes" << std::endl;
	// }
	// else {
	// 	std::cout << "No" << std::endl;
	// }


	// on met du code qui peut renvoyer une exception...

	return 0;
}
