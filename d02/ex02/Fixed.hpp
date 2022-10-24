#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

class Fixed
{

public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed(int int_pt);
	Fixed(float float_pt);
	~Fixed();

	Fixed &operator=(Fixed const &rhs);
	bool operator>(Fixed const &rhs);
	bool operator<(Fixed const &rhs);
	bool operator>=(Fixed const &rhs);
	bool operator<=(Fixed const &rhs);
	bool operator==(Fixed const &rhs);
	bool operator!=(Fixed const &rhs);
	Fixed operator+(Fixed const &rhs);
	Fixed operator-(Fixed const &rhs);
	Fixed operator*(const Fixed &rhs);
	Fixed operator/(Fixed const &rhs);
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &obj1, Fixed &obj2);
	static Fixed &min(Fixed const &obj1, Fixed const &obj2);
	static Fixed &max(Fixed &obj1, Fixed &obj2);
	static Fixed &max(Fixed const &obj1, Fixed const &obj2);

private:
	int _fixed_nb;
	static const int _bits_nb = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif /* *********************************************************** FIXED_H */
