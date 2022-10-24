#include "Fixed.hpp"

int main(void)
{
	Fixed b(5.05f);
	Fixed c(2.9999f);
	Fixed d(b * c);

	std::cout << "b_nb: " << d.getRawBits() << std::endl;
	//	std::cout << b.getRawBits() << std::endl;
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}
