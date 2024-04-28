#include "../inc/PmergeMe.hpp"

int	isNumber(char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check(int ac, char **av)
{
	int	i = 1;
	int	sorted = 0;

	if (ac == 1)
		throw std::runtime_error("Incorrect amount of arguments");
	while (i < ac)
	{
		if (!isNumber(av[i]))
			throw std::runtime_error("Invalid Element");
		if (i + 1 < ac && atoi(av[i]) > atoi(av[i + 1]))
			sorted = 1;
		i++;
	}
	if (sorted == 0)
		throw std::runtime_error("Already Sorted");
	return (0);
}

int	main(int ac, char **av)
{
	try
	{
		check(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " <<  e.what() << '\n';
		return (1);
	}
	PmergeMe	Pme;
	
	Pme.FJsort(ac, av);
	return (0);
}