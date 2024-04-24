
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

void	printVectorPair(std::vector<std::pair<int, int> > v)
{
	int	i = 0;
	for (std::vector<std::pair<int, int> >::iterator it = v.begin(); it < v.end(); it++)
	{
		std::cout << "[" << i++ << "]: <";
		std::cout << it->first;
		std::cout << ", " << it->second << ">\n";
	}
	
}

void	printVector(std::vector<int> vec)
{
	int	i = 0;
	for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
	{
		std::cout << "[" << i++ << "]: ";
		std::cout << *it << "\n";
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
	printVectorPair(v);
	std::cout << "\nFIRST SORT:\n";
	for (int i = 0; i < n / 2; i++)
		firstSort(i);
	printVectorPair(v);
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
	int	buf = 2147483647;
	int	maxPos = 0;
	std::pair<int, int> p;

	for (int i = start; i < n / 2; i++)
	{
		if (v[i].first < buf)
		{
			p = v[i];
			buf = v[i].first;
			maxPos = i;
		}
	}
	v.erase(v.begin() + maxPos);
	v.insert(v.begin() + start, p);
}

int	PmergeMe::binaryInsertion(std::vector<int> vec, int b)
{
	int	low = 0;
	int	high = vec.size();
	int	mid = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (b <= vec[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (low);
}

int	J(int n)
{
	if (n == 1)
		return (1);
	if (n == 0)
		return (0);
	return (J(n - 1) + (2 * J(n - 2)));
}

void	PmergeMe::pushA(void)
{
	std::vector<std::pair<int, int> >::iterator	a;

	for (a = v.begin(); a < v.end(); a++)
	{
		if (a->first == -1)
			continue ;
		sorted.push_back(a->first);
	}
	std::cout << "\nA VECTOR:\n";
	printVector(sorted);
}

void	PmergeMe::sequenceInit(void)
{
	for (int i = 0; i < (int)v.size(); i++)
	{
		int j = J(i + 1) - J(i);
		if (j >= 0)
			Jacob.push_back(j);
	}
}

void	PmergeMe::FordJohnson(void)
{
	sequenceInit();
	pushA();

	int	x = 0;
	int	y = Jacob[2];
	int	w = 0;
	for (int i = 2; i < (int)v.size() && y <= (int)v.size(); i++)
	{
		for (x = y - 1; x >= w; x--)
		{
			if (v[x].second > sorted[sorted.size() - 1])
				sorted.push_back(v[x].second);
			else
				sorted.insert(sorted.begin() + binaryInsertion(sorted, v[x].second), v[x].second);
		}
		w = y;
		y += Jacob[i];
		if (y + Jacob[i] >= v.size())
			y = v.size();
	}
	printVector(sorted);
}
