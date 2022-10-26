#include "Point.hpp"

float	dist(Point pt1, Point pt2)
{
	float	pt1_x = pt1.get_x();
	float	pt1_y = pt1.get_y();
	float	pt2_x = pt2.get_x();
	float	pt2_y = pt2.get_y();
	float	dist;

	dist = sqrt(pow(pt2_x - pt1_x, 2) + pow(pt2_y - pt1_y, 2));
	return (dist);
}

Point	vector(Point pt1, Point pt2)
{
	Point	vector(pt2.get_x() - pt1.get_x(), pt2.get_y() - pt1.get_y());
	return (vector);
}

float	dot(Point vec1, Point vec2)
{
	return (vec1.get_x() * vec2.get_x() + vec1.get_y() * vec2.get_y());
}

float	angle(Point p, Point a, Point b)
{
	Point	vec1 = vector(p, a);
	Point	vec2 = vector(p, b);
	float	dist1 = dist(p, a);
	float	dist2 = dist(p, b);
	float	angle = acos(dot(vec1, vec2)/(dist1*dist2));

	return (angle);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	angle1 = angle(point, a, b);
	float	angle2 = angle(point, b, c);
	float	angle3 = angle(point, c, a);
	float	sum;
	if (a.is_equal(b) || a.is_equal(c) || b.is_equal(c)) {
		std::cout << "This is not a triangle !" << std::endl;
		exit(1);
	}
	if (point.is_equal(a) || point.is_equal(b) || point.is_equal(c)) {
		std::cout << "The point coincides with one of the edges !" << std::endl;
		exit(1);
	}

	sum = angle1 + angle2 + angle3;
	return (Fixed(sum) == Fixed((float)(2 * M_PI)));
}
