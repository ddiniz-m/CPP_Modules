
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
		~Fixed();
		Fixed(const Fixed &t);
		Fixed& operator=(const Fixed &t);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif