#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <cstring>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class	RPN
{
	private:
		int				n;
		int				op;
		std::stack<int>	nums;

	public:
		RPN();
		~RPN();
		RPN& operator=(const RPN &copy_a);
		RPN(const RPN &copy);

		void	stackOps(std::string token);
		void	rpn(std::string str);
		void	run(std::string str);
		void	checkRPN(std::string str);
};


#endif

