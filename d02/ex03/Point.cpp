#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : _x(0), _y(0)
{
}

Point::Point(Fixed ft_x, Fixed ft_y) : _x(ft_x), _y(ft_y)
{
}

Point::Point( const Point & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	this->~Point();
	return *new(this) Point(rhs._x, rhs._y);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool				Point::is_equal(Point pt2) const
{
	return ( this->get_x_fixed() == pt2.get_x_fixed() && this->get_y_fixed() == pt2.get_y_fixed());
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
Fixed				Point::get_x_fixed() const
{
	return(_x);
}

Fixed				Point::get_y_fixed() const
{
	return (_y);
}

float				Point::get_x()
{
	return (_x.toFloat());
}

float				Point::get_y()
{
	return (_y.toFloat());
}

/* ************************************************************************** */
