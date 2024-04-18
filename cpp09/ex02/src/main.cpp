#include "../inc/PmergeMe.hpp"

//list<T>
//vector<T>

int	main(int ac, char **av)
{
	if (ac <= 2)
	{
		std::cout << RED << "Error: Incorrect amount of arguments!\n";
		std::cout << GREEN << "Usage: ./PmergeMe 5 4 3 2 1\n" << NC;
		return (1);
	}
	PmergeMe	Pme;
	Pme.pairVector(ac, av);
	return (0);
}