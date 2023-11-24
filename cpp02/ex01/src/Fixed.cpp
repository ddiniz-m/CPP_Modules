
#include "../inc/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GREEN << "Default Constructor Called" << NC << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &t)
{
	std::cout << GREEN << "Copy Constructor Called" << NC << std::endl;
	*this = t;
}

Fixed::Fixed(const int i)
{
	std::cout << GREEN << "Int Constructor Called" << NC << std::endl;
	this->setRawBits((i << bit));
}

Fixed::Fixed(const float f)
{
	std::cout << GREEN << "Float Constructor Called" << NC << std::endl;
	this->setRawBits(roundf(f * (1 << bit)));
}

Fixed& Fixed::operator=(const Fixed &t)
{
	std::cout << GREEN << "Copy Assignment Operator Called" << NC << std::endl;
	this->setRawBits(t.getRawBits());
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

float	Fixed::toFloat(void) const
{
	float f;

	f = (float)this->getRawBits() / (1 << bit);
	return (f);
}

int		Fixed::toInt(void) const
{
	int	i;

	i = this->getRawBits() >> bit;
	return (i);
}

std::ostream& operator<<(std::ostream &ostream, Fixed const &n)
{
	ostream << n.toFloat();
	return (ostream);
}