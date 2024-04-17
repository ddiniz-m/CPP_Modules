
#include "../inc/PmergeMe.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
PmergeMe::PmergeMe()
{
	std::cout << GREEN << "PmergeMe Default Constructor Called" << NC << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &copy_a)
{
	std::cout << GREEN << "PmergeMe Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	std::cout << GREEN << "PmergeMe Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

PmergeMe::~PmergeMe()
{
	std::cout << RED << "PmergeMe Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	printVector(std::vector<int> v)
{
	std::cout << "<";
	for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != v.end())
			std::cout << ", ";
	}
	std::cout << ">\n";
}

void	PmergeMe::printList(void)
{
	std::cout << "List:\n";
	for (std::list<std::vector<int> >::iterator	it = lst.begin(); it != lst.end(); it++)
	{
		printVector(*it);
	}
	
}

void	PmergeMe::pairUp(int ac, char **av)
{
	int	i;

	for (i = 1; i <= ac - 1; i++)
	{
		std::vector<int>	v;
		v.push_back(atoi(av[i++]));
		if (i <= ac - 1)
			v.push_back(atoi(av[i]));
		lst.push_back(v);
		printVector(v);
	}
	printList();
}
