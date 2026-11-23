#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {
    public:

        Point();
        Point(float const _x, float const _y);
        Point(Point const &other);
        Point & operator=(Point const & other);
        ~Point();
        Fixed   getX () const;
        Fixed   getY () const;

        private:
        Fixed const _x;
        Fixed const _y;
};
bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif