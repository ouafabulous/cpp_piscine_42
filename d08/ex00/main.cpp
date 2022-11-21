#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v_numbers;
	v_numbers.push_back(1);
	v_numbers.push_back(2);
	v_numbers.push_back(3);
	std::list<int> l_numbers;
	l_numbers.push_back(1);
	l_numbers.push_back(2);
	l_numbers.push_back(3);
	// std::list<float> bad_numbers;
	// bad_numbers.push_back(1.1);
	// bad_numbers.push_back(2.2);
	// bad_numbers.push_back(3.3);

	try {
	std::cout << easyfind(v_numbers, 1) << std::endl;
	std::cout << easyfind(v_numbers, 10) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
		try {
			std::cout << easyfind(l_numbers, 1) << std::endl;
			std::cout << easyfind(l_numbers, 10) << std::endl;
			// std::cout << easyfind(bad_numbers, 1) << std::endl;
			// std::cout << easyfind(bad_numbers, 10) << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what();
		}
	}
		return 0;
}
