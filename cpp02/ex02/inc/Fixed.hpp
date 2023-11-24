
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define NC "\033[0m"

class	Fixed
{
	private:
		int					value;
		static const int	bit = 8;

	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &t);
		~Fixed();
		Fixed& operator=(const Fixed &t);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed& operator>(const Fixed &t);
		Fixed& operator<(const Fixed &t);
		Fixed& operator>=(const Fixed &t);
		Fixed& operator<=(const Fixed &t);
		Fixed& operator==(const Fixed &t);
		Fixed& operator++(const Fixed &t);
		Fixed& operator--(const Fixed &t);
		Fixed& operator++(const Fixed &t, int);
		Fixed& operator--(const Fixed &t, int);
};

std::ostream& operator<<(std::ostream &ostream, Fixed const &n);

#endif