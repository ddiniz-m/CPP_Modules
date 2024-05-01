#include "../inc/RPN.hpp"

//stack<int>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Error: Incorrect amount of arguments!\n";
		std::cout << GREEN << "Usage: ./RPN \"8 9 * 9 -\"\n" << NC;
		return (1);
	}
	if (!*av[1])
	{
		std::cout << RED << "Error: Empty String\n" << NC;
		return (1);
	}
	RPN	rpn;
	std::string	arg1;

	arg1 = av[1];
	rpn.run(arg1);
	return (0);
}