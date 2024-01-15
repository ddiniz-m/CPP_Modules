
#include "../inc/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(2.5, 3.5);
	Point b(1.2, 2.2);
	Point c(5.4, 3.0);

	Point p[] = {
		Point(1, 1),
		Point(2, 2)
	};
	
	bsp(a, b, c, p);
}