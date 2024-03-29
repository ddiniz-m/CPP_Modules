
#include "../inc/Fixed.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Fixed::Fixed()
{
	std::cout << GREEN << "Default Constructor Called" << NC << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &t)
{
	std::cout << GREEN << "Copy Constructor Called" << NC << std::endl;
	*this = t;
}

Fixed& Fixed::operator=(const Fixed &t)
{
	std::cout << GREEN << "Copy Assignment Operator Called" << NC << std::endl;
	this->value = t.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

int Fixed::getRawBits(void) const
{
	std::cout << YELLOW << "getRawBits Member Function Called" << NC << std::endl;
	return(this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
