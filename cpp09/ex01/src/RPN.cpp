
#include "../inc/RPN.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
RPN::RPN()
{
	std::cout << GREEN << "RPN Default Constructor Called" << NC << std::endl;
}

RPN& RPN::operator=(const RPN &copy_a)
{
	std::cout << GREEN << "RPN Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

RPN::RPN(const RPN &copy)
{
	std::cout << GREEN << "RPN Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

RPN::~RPN()
{
	std::cout << RED << "RPN Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

