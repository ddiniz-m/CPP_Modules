#include "../inc/RPN.hpp"

//stack<class T, <std::deque<T> >

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Incorrect amount of arguments!\n";
		std::cout << GREEN << "Usage: ./RPN \"8 9 * 9 -\"\n" << NC;
		return (1);
	}
	RPN	rpn;

	rpn.parse(av[1]);
	return (0);
}