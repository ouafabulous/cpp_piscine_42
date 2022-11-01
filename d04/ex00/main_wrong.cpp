#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *i = new WrongCat();

	std::cout << YELLOW << i->getType() << " " << RESET << std::endl;
	i->makeSound(); // will  not output the cat sound!
	meta->makeSound();
	delete i;
	delete meta;
	return 0;
}
