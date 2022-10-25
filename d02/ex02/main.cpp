#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed	e;
Fixed	b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed	c(5.05f);
Fixed	d(2);
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << c << std::endl;
std::cout << d << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( b, e ) << std::endl;
return 0;
}
