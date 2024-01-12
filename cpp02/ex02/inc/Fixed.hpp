
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"

class	Fixed
{
	private:
		int					value;
		static const int	bit = 8;

	public:
		Fixed();
		Fixed(const Fixed &n);
		Fixed& operator=(const Fixed &n);
		~Fixed();

		Fixed(const int i);
		Fixed(const float f);

		bool operator>(const Fixed &n);
		bool operator<(const Fixed &n);
		bool operator>=(const Fixed &n);
		bool operator<=(const Fixed &n);
		bool operator==(const Fixed &n);
		bool operator!=(const Fixed &n);
		Fixed operator+(const Fixed &n);
		Fixed operator-(const Fixed &n);
		Fixed operator*(const Fixed &n);
		Fixed operator/(const Fixed &n);
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed& min(Fixed &n1, Fixed &n2);
		static Fixed& max(Fixed &n1, Fixed &n2);
		static const Fixed& min(const Fixed &n1, const Fixed &n2);
		static const Fixed& max(const Fixed &n1, const Fixed &n2);
};

std::ostream& operator<<(std::ostream &ostream, Fixed const &n);

#endif