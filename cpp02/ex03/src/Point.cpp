#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Point::Point() : x(0), y(0)
{
	//std::cout << GREEN << "Point Default Constructor Called" << NC << std::endl;
}

Point::Point(const Point &copy)  : x(copy.x), y(copy.y)
{
	//std::cout << GREEN << "Point Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Point& Point::operator=(const Point &copy_a)
{
	//std::cout << GREEN << "Point Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

Point::~Point()
{
	//std::cout << RED << "Point Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

Point::Point(const float a, const float b) : x(a), y(b)
{
	;
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}