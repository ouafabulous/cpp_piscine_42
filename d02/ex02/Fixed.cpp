#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _fixed_nb(0)
{
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(int const int_pt) : _fixed_nb(int_pt * (1 << _bits_nb))
{
}

Fixed::Fixed(float const float_pt) : _fixed_nb(roundf(float_pt * (1 << _bits_nb)))
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
	{
		this->_fixed_nb = rhs._fixed_nb;
	}
	return *this;
}

bool Fixed::operator>(Fixed const &rhs)
{
	return (this->_fixed_nb > rhs._fixed_nb);
}

bool Fixed::operator>=(Fixed const &rhs)
{
	return (this->_fixed_nb >= rhs._fixed_nb);
}

bool Fixed::operator<(Fixed const &rhs)
{
	return (this->_fixed_nb < rhs._fixed_nb);
}

bool Fixed::operator<=(Fixed const &rhs)
{
	return (this->_fixed_nb <= rhs._fixed_nb);
}

bool Fixed::operator==(Fixed const &rhs)
{
	return (this->_fixed_nb == rhs._fixed_nb);
}

bool Fixed::operator!=(Fixed const &rhs)
{
	return (this->_fixed_nb != rhs._fixed_nb);
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	return (Fixed(this->_fixed_nb + rhs._fixed_nb));
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	return (Fixed(this->_fixed_nb - rhs._fixed_nb));
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	Fixed result;

	int mul = this->_fixed_nb * rhs._fixed_nb;
	result._fixed_nb = (mul >> _bits_nb);
	return (result);
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	Fixed result;

	if (!rhs.getRawBits())
	{
		std::cout << "Error: Division by 0" << std::endl;
		exit(1);
	}
	int div = this->_fixed_nb * rhs._fixed_nb;
	result._fixed_nb = div << _bits_nb;
	return (result);
}

Fixed &Fixed::operator++()
{
	this->_fixed_nb++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->_fixed_nb--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return (temp);
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

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return (obj1 < obj2 ? obj1 : obj2);
}

Fixed const &Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
	return (obj1.toFloat() < obj2.toFloat() ? obj1 : obj2);
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return (obj1 > obj2 ? obj1 : obj2);
}

Fixed const &Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	return (obj1.toFloat() > obj2.toFloat() ? obj1 : obj2);
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
