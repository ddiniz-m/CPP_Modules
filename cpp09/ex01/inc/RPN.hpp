#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class RPN
{
	private:
		
	public:
		RPN();
		~RPN();
		RPN& operator=(const RPN &copy_a);
		RPN(const RPN &copy);
};

#endif

