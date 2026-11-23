#include "Point.hpp"

Point::Point() : _x(0) ,_y(0)
{}

Point::Point(float const x, float const y) : _x(x), _y(y)
{}

Point::Point(Point const &other) : _x(other._x), _y(other._y)
{}
Point::~Point()
{}
Point & Point::operator=(Point const & other)
{
    (void)other;
	return (*this);
}

Fixed Point::getX() const
{
    return (this->_x);
}

Fixed Point::getY() const
{
    return (this->_y);
}


static Fixed cross(Point const & a, Point const & b, Point const & p)
{
	return ((b.getX() - a.getX()) * (p.getY() - a.getY())
		- (b.getY() - a.getY()) * (p.getX() - a.getX()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = cross(a, b, point);
	Fixed d2 = cross(b, c, point);
	Fixed d3 = cross(c, a, point);

	bool hasNeg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	bool hasPos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

	if (hasNeg && hasPos)
		return (false);
	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return (false);
	return (true);
}