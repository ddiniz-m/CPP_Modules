#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>

#define NC "[0m"
#define RED "[0;31m"
#define GREEN "[0;32m"
#define YELLOW "[0;33m"
#define MAGENTA "[0;35m"

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

