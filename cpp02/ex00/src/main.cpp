
#include "../inc/Fixed.hpp"

int	main()
{
	Fixed a;	//Default
	Fixed b(a); //Copy
	Fixed c;
	c = b;		//Assignment Operator
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << std::endl << std::endl;

	a.setRawBits(2);
	Fixed d;
	d = a;
	Fixed e(a);
	Fixed f(e);

	std::cout << a.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	std::cout << e.getRawBits() << std::endl;
	std::cout << f.getRawBits() << std::endl;
	return (0);
}