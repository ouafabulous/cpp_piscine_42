#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{

public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed(int const int_pt);
	Fixed(float const float_pt);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed	&operator=(Fixed const &rhs);

private:
	int					_fixed_nb;
	static const int	_bits_nb = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif /* *********************************************************** FIXED_H */
