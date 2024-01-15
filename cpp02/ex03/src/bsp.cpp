#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

Fixed	abs(Fixed f)
{
	if (f < 0)
		return (f * (-1));
	return (f)
}

Fixed	area(Point const x, Point const y, Point const z)
{
	Fixed X, Y, Z;
	X = x.getX() * (y.getY() - z.getY());
	Y = y.getX() * (z.getY() - x.getY());
	Z = z.getX() * (x.getY() - y.getY());
	return(abs((X + Y + Z)/2))
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = area(a, b ,c);
	if (A == 0)
		return (0);

	Fixed PAB = area(point, a, b);
	Fixed PAC = area(point, a ,c);
	Fixed PBC = area(point, b, c);
	if (PAB == 0 || PAC == 0 || PBC == 0)
		return (0);

	if (A == PAB + PAC + PBC)
		return (1);
	return (0);
}