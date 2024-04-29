
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

void	printStack(std::stack<int> s)
{
	int		i = 0;
	while (!s.empty())
	{
		i = s.top();
		if (strchr("+-/*", i))
			std::cout << (char)i << "\n";
		else
			std::cout << i << "\n";
		s.pop();
	}
}

int	operation(int n1, int n2, int op)
{
	switch (op)
	{
	case '+':
		return (n1 + n2);
	case '-':
		return (n1 - n2);
	case '*':
		return (n1 *n2);
	case '/':
	{
		if (n2 == 0)
			throw std::invalid_argument("Cannot divide by 0!");
		return (n1 / n2);
	}
	default:
		break;
	}
	return (0);
}

void	RPN::stackOps(std::string token)
{
	int	i = atoi(token.c_str());
	int	n1, n2;

	if (token.find_first_not_of("0123456789") == std::string::npos)
		nums.push(i);
	else if (nums.size() <= 1)
		throw std::runtime_error("Wrong Expression");
	else if (token.size() == 1 && strchr("+-*/", token[0]))
	{
		n2 = nums.top();
		nums.pop();
		n1 = nums.top();
		nums.pop();
		nums.push(operation(n1, n2 ,token[0]));
	}
	else if (isspace(i))
		;
	else
		throw std::runtime_error("Invalid Character");
}

void	RPN::checkRPN(std::string str)
{
	n = 0;
	op = 0;
	std::istringstream	iss(str);
	std::string			token;

	while (iss >> token)
	{
		if (atoi(token.c_str()) < 0)
			throw std::runtime_error("Invalid Input");
		if (token.find_first_not_of("0123456789") == std::string::npos)
			n++;
		if (token.size() == 1 && strchr("+-*/", token[0]))
			op++;
	}
	if (n - 1 != op || op == 0)
		throw std::runtime_error("Wrong Expression");
}

void	RPN::rpn(std::string str)
{
	std::istringstream	iss(str);
	std::string			token;

	try
	{
		checkRPN(str);
		while (iss >> token)
			stackOps(token);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
		throw 1;
	}
	return ;
}


void	RPN::run(std::string str)
{
	try
	{
		rpn(str);
	}
	catch(int i)
	{
		return ;
	}
	std::cout << nums.top() << '\n';
}