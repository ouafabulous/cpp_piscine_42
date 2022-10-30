#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal* j = new Dog();
	const Animal *i = new Cat();

	std::cout << MAGENTA << j->getType() << " " << RESET << std::endl;
	std::cout << YELLOW << i->getType() << " " << RESET << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound(); // will output the dog sound!
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	return 0;
}
