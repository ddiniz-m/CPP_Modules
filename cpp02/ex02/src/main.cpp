
#include "../inc/Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl << std::endl;

	Fixed d(10);
	Fixed e(0);
	Fixed f(10.1f);
	std::cout << "d: "<< d << std::endl;
	std::cout << "e: "<< e << std::endl;
	std::cout << "f: "<< f << std::endl << std::endl;

	std::cout << "d + e  : " << d + e << std::endl;
	std::cout << "d - e  : " << d - e << std::endl;
	std::cout << "d * e  : " << d * e << std::endl;
	std::cout << "d / e  : " << d / e << std::endl;

	std::cout << "d > e  : " << (d > e) << std::endl;
	std::cout << "d < e  : " << (d < e) << std::endl;
	std::cout << "d >= e : " << (d >= e) << std::endl;
	std::cout << "d <= e : " << (d <= e) << std::endl;
	std::cout << "d != e : " << (d != e) << std::endl;
	std::cout << "d == e : " << (d == e) << std::endl;
	std::cout << "d == d : " << (d == d) << std::endl << std::endl;

	std::cout << "d++ : " << d++ << std::endl;
	std::cout << "d   : " << d << std::endl;
	std::cout << "d-- : " << d-- << std::endl;
	std::cout << "d   : " << d << std::endl << std::endl;

	std::cout << "++d : " << ++d << std::endl;
	std::cout << "d   : " << d << std::endl;
	std::cout << "--d : " << --d << std::endl;
	std::cout << "d   : " << d << std::endl << std::endl;

	Fixed g(10);
	Fixed h(11);
	std::cout << "min: " << Fixed::min(g, h) << std::endl;
	std::cout << "max: " << Fixed::max(g, h) << std::endl << std::endl;

	Fixed const i(2.2f);
	Fixed const j(78.9f);
	std::cout << "const min: " << Fixed::min(i, j)  << std::endl;
	std::cout << "const max: " << Fixed::max(i, j) << std::endl;
	return 0;
}