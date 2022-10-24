#include "Fixed.hpp"

// const int Fixed::_bits_nb = 12;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()  : _fixed_nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const int_pt) : _fixed_nb(int_pt * (1 << _bits_nb))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const float_pt) : _fixed_nb(float_pt * (1 << _bits_nb))
{
	std::cout << "Float constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_fixed_nb = rhs._fixed_nb;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat(void) const
{
	return (((float)_fixed_nb / (1 << _bits_nb)));
}

int Fixed::toInt(void) const
{
	return (roundf(_fixed_nb / (1 << _bits_nb)));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Fixed::setRawBits(int const raw)
{
	_fixed_nb = raw;
}

int Fixed::getRawBits(void) const
{
	return (_fixed_nb);
}

/* ************************************************************************** */
