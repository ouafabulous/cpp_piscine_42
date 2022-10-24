#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _fixed_nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	(void)src;
	std::cout << "Copy constructor called with _nb_: " << src._fixed_nb << std::endl;
}

Fixed::Fixed(int int_pt) : _fixed_nb(int_pt * (1 << _bits_nb))
{
	std::cout << "Int constructor called with " << int_pt << std::endl;
}

Fixed::Fixed(float float_pt) : _fixed_nb(float_pt * (1 << _bits_nb))
{
	std::cout << "float constructor called with " << float_pt << std::endl;
	// std::cout << "Float constructor called" << std::endl;
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
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_nb = rhs._fixed_nb;
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
	std::cout << "multiplication result between " << this->getRawBits() << " and " << rhs.getRawBits() << "is: " << this->getRawBits() * rhs.getRawBits() << std::endl;
	return Fixed(2);
	return (Fixed((float)(this->getRawBits()) * (float)(rhs.getRawBits())));
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	if (!rhs.getRawBits())
	{
		std::cout << "Error: Division by 0" << std::endl;
		exit(1);
	}
	return (Fixed(this->_fixed_nb / rhs._fixed_nb));
}

Fixed &Fixed::operator++()
{
	// std::cout << "()++" << std::endl;
	this->_fixed_nb++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	// std::cout << "++()" << std::endl;
	Fixed temp = *this;
	this->_fixed_nb++;
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
	(*this)--;
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
	if (obj1 < obj2)
	{
		return (obj1);
	}
	return (obj2);
}

Fixed &Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
	Fixed temp;

	if (obj1.getRawBits() < obj2.getRawBits())
	{
		temp = Fixed(obj1.getRawBits());
	}
	else
	{
		temp = Fixed(obj2.getRawBits());
	}
	Fixed &temp2 = temp;
	return (temp2);
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1 > obj2)
	{
		return (obj1);
	}
	return (obj2);
}

Fixed &Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	Fixed temp;

	if (obj1.getRawBits() > obj2.getRawBits())
	{
		temp = Fixed(obj1.getRawBits());
	}
	else
	{
		temp = Fixed(obj2.getRawBits());
	}
	Fixed &temp2 = temp;
	return (temp2);
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
