#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

#define NC "\033[0m"
#define RED  "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"

class	Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float a, const float b);
		Point(const Point &n);
		Point& operator=(const Point &n);
		~Point();
};

#endif