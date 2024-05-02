#include "../inc/PmergeMe.hpp"
#include <string.h>

int	isValid(char *str)
{
	if (!str || !*str || atoi(str) < 0)
		return (0);
	if (*str == '+' && strlen(str) > 1)
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	duplicate(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		for (int j = i + 1; j < ac; j++)
			if (atoi(av[j]) == atoi(av[i]))
				return (1);
	return (0);
}

int	check(int ac, char **av)
{
	int	i = 1;
	int	sorted = 0;

	if (ac == 1)
		throw std::runtime_error("Incorrect amount of arguments");
	if (duplicate(ac, av))
		throw std::runtime_error("Duplicate elements");
	while (i < ac)
	{
		if (!isValid(av[i]))
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