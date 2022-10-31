#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	// AAnimal	test;

	AAnimal	*dogs_and_cats[10];
	for (int i = 0; i != 10; i++) {
		if (i % 2) {
			dogs_and_cats[i] = new Cat();
		}
		else {
			dogs_and_cats[i] = new Dog();
		}
	}
	for (int i = 0; i != 10; i++) {
			delete dogs_and_cats[i];
	}


	return 0;
}
