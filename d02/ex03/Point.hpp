#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

# define EPSILON 0.000001

class Point
{

	public:

		Point();
		Point(Fixed ft_x, Fixed ft_y);
		Point(Point const & src);
		~Point();

		Point &		operator=(Point const & rhs);
		Point &		operator==(Point const & rhs);

		float		get_x();
		float		get_y();
		Fixed		get_x_fixed() const;
		Fixed		get_y_fixed() const;
		bool		is_equal(Point pt2) const;

	private:

		Fixed const	_x;
		Fixed const	_y;

};

// std::ostream &			operator<<( std::ostream & o, Point const & i );
float	angle(Point p, Point a, Point b);
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* *********************************************************** POINT_H */
