#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Point::Point()
{
	std::cout << GREEN << "Point Default Constructor Called" << NC << std::endl;
	x(0);
	y(0);
}

Point::Point(const Point &copy)
{
	std::cout << GREEN << "Point Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Point& Point::operator=(const Point &copy_a)
{
	std::cout << GREEN << "Point Copy Assignment Operator Called" << NC << std::endl;
	return (*this);
}

Point::~Point()
{
	std::cout << RED << "Point Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

Point::Point(const float a, const float b)
{
	x(a);
	x(b);
}