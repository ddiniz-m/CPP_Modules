
#include "../inc/Fixed.hpp"

int	main()
{
	/* Fixed test1, test2; */  //Default constructor
	/* test2 = test1; */		 //Assignament operator contsructor
	/* Fixed test3 = test1; */ //Copy constructor

	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << std::endl;

	return (0);
}