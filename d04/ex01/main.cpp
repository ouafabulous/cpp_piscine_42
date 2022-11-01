#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	// Cat	*i_1 = new Cat();

	// i_1->setIdea("I love my master", 0);
	// Cat	*i_2 = new Cat(*i_1);

	// delete i_1;
	// std::cout << "I'm the idea issued from the deep copy, and here I am: " << i_2->getIdea(0) << std::endl;

	// delete i_2;

	Animal	*dogs_and_cats[10];
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

	// Dog basic;
	// {
	// 	Dog tmp;
	// 	tmp.setIdea("Jadore le CPP", 0);
	// 	basic = tmp;
	// }
	// std::cout << basic.getIdea(0) << std::endl;

	return 0;
}
