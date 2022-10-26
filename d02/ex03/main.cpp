#include "Point.hpp"

int main()
{
	Point	a1(1, 0);
	Point	b1(3, 0);
	Point	c1(2, 2);
	Point	p1(2, 1);

	Point	a2(1, 0);
	Point	b2(1, 0);
	Point	c2(2, 2);
	Point	p2(2, 1);

	Point	a3(1, 0);
	Point	b3(2, 1);
	Point	c3(2, 2);
	Point	p3(2, 1);

	Point	a4(1, 0);
	Point	b4(2, 1);
	Point	c4(2, 2);
	Point	p4(2, 1.001f);

	Point	a5(1, 0);
	Point	b5(2, 1);
	Point	c5(2, 2);
	Point	p5(2, 1.005f);

	bool	res = bsp(a1, b1, c1, p1);
	// bool	res = bsp(a2, b2, c2, p2);
	// bool	res = bsp(a3, b3, c3, p3);
	// bool	res = bsp(a4, b4, c4, p4);
	// bool	res = bsp(a5, b5, c5, p5);

	if (res) {
		std::cout << "Point inside the triangle" << std::endl;
	}
	else {

		std::cout << "Point outside the triangle" << std::endl;
	}
	return (0);
}
