
#include "../inc/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GREEN << "Default Constructor Called" << NC << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &t)
{
	(void)t;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &t)
{
	(void)t;
	std::cout << "Copy Assignment Operator Called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor Called" << NC << std::endl;
}

int Fixed::getRawBits(void) const
{
	return(this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}