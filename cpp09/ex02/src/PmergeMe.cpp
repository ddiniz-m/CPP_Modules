
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

void	printVector(std::vector<std::pair<int, int> > v)
{
	int	i = 0;
	for (std::vector<std::pair<int, int> >::iterator it = v.begin(); it < v.end(); it++)
	{
		std::cout << "[" << i++ << "]: <";
		std::cout << it->first;
		std::cout << ", " << it->second << ">\n";
	}
	
}

void	PmergeMe::pairVector(int ac, char **av)
{
	int	i;
	int	n1 = 0;

	n = ac - 1;
	for (i = 1; i <= n; i++)
	{
		n1 = atoi(av[i++]);
		if (i <= n)
			v.push_back(makePair(n1, atoi(av[i])));
		else
			v.push_back(makePair(-1, n1));
	}
	printVector(v);
	std::cout << "\nFIRST SORT:\n";
	for (int i = 0; i < n / 2; i++)
		firstSort(i);
	printVector(v);
}

std::pair<int, int>	PmergeMe::makePair(int n1, int n2)
{
	std::pair<int, int>	p;

	if (n1 <= n2)
	{
		p.first = n1;
		p.second = n2;
	}
	else
	{
		p.first = n2;
		p.second = n1;
	}
	return (p);
}

//sorts by pairs' largest value
void	PmergeMe::firstSort(int	start)
{
	int	buf = -1;
	int	maxPos = 0;
	std::pair<int, int> p;

	for (int i = start; i < n / 2; i++)
	{
		if (v[i].first > buf)
		{
			p = v[i];
			buf = v[i].first;
			maxPos = i;
		}
	}
	v.erase(v.begin() + maxPos);
	v.insert(v.begin() + start, p);
}

void	PmergeMe::FordJohnson(void)
{
	;
}