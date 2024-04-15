
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

void	printStack(std::stack<int, std::deque<int> > s)
{
	char	c;
	while (!s.empty())
	{
		c = s.top();
		std::cout << c << "\n";
		s.pop();
	}
}

void	RPN::parse(char *str)
{
	if (!str)
		return;
	while (*str)
	{
		if (isdigit(*str) && *str + 1 && !isspace(*str + 1))
			nums.push(*str++);
		else if (strchr("+-/*", *str))
			ops.push(*str++);
		else if (isspace(*str))
			str++;
		else
			std::cout << "Invalid Character: " << *str++ << "\n";
	}
	std::cout << "NUMBERS:\n";
	printStack(nums);
	std::cout << "OPERATORS:\n";
	printStack(ops);
	return ;
}