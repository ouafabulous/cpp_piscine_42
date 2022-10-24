#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

class Fixed
{

public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed(int const int_pt);
	Fixed(float const float_pt);
	~Fixed();

	Fixed &operator=(Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fixed_nb;
	static const int _bits_nb = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif /* *********************************************************** FIXED_H */
