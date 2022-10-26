#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{

public:
	Fixed();
	Fixed(const Fixed &src);
	~Fixed();

	Fixed &operator=(Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int					_fixed_nb;
	static const int	_bits_nb = 8;
};

#endif /* *********************************************************** FIXED_H */
