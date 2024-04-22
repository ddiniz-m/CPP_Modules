
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
		if (b < vec[mid])
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

void	PmergeMe::FordJohnson(void)
{
	std::vector<std::pair<int, int> >::iterator	a;
	std::vector<std::pair<int, int> >::iterator	b;
	std::vector<std::pair<int, int> >::iterator	it;

	b = v.begin();
	for (a = v.begin(); a < v.end(); a++)
	{
		if (a->first == -1)
			continue ;
		sorted.push_back(a->first);
	}
	sorted.insert(sorted.begin() + binaryInsertion(sorted, b->second), b->second);
	std::cout << "\nA VECTOR:\n";
	printVector(sorted);

	int	i;
	int	j;
	int	k;


	i = 2;
	k = J(i);
	j = (2 * J(k));
	for (b = v.begin() + j; b < v.end(); b += j)
	{
		std::cout << "Jacob k: " << k << "\n";
		std::cout << "FJ    j: " << j << "\n";
		std::cout << "SIZE: " << v.size() << "\n";
		while ((unsigned long)j > v.size()) //this is wrong
			j--;
		it = v.begin() + j;
		k = j;
		while (k > 0)
		{
			sorted.insert(sorted.begin() + binaryInsertion(sorted, it->second), it->second);
			std::cout << "b->second: " << it->second << "\n";
			it--;
			k--;
		}
		k = J(i);
		j = (2 * J(k));
		i++;
	}

	std::cout << "\nSORTED??:\n";
	printVector(sorted);
}
