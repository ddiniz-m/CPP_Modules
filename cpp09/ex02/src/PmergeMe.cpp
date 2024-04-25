
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

int	J(int n)
{
	if (n == 1)
		return (1);
	if (n == 0)
		return (0);
	return (J(n - 1) + (2 * J(n - 2)));
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

int	binaryInsertionVector(std::vector<int> &v, int b)
{
	int	low = 0;
	int	high = v.size();

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (b <= v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (low);
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
	for (int i = 0; i < n / 2; i++)
		firstSortVector(i);
}

//sorts by pairs' largest value
void	PmergeMe::firstSortVector(int	start)
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

void	PmergeMe::pushAVector(std::vector<std::pair<int, int> > &v)
{
	std::vector<std::pair<int, int> >::iterator	a;

	for (a = v.begin(); a < v.end(); a++)
	{
		if (a->first == -1)
			continue ;
		sortedVector.push_back(a->first);
	}
}

void	PmergeMe::sequenceInitVector(void)
{
	Jacob.reserve(15);
	for (int i = 0; i < 15; i++)
	{
		int j = J(i + 1) - J(i);
		if (j >= 0)
			Jacob.push_back(j);
	}
}

/* sortedVector.insert(std::upper_bound(sortedVector.begin(), sortedVector.end(), v[x].second), v[x].second) */
void	PmergeMe::FordJohnsonVector(void)
{
	sequenceInitVector();
	pushAVector(v);

	int	x = 0;
	int	y = Jacob[2];
	int	w = 0;
	for (int i = 2; i < (int)Jacob.size() && y <= (int)v.size(); i++)
	{
		for (x = y - 1; x >= w; x--)
		{
			if (v[x].second > sortedVector[sortedVector.size() - 1])
				sortedVector.push_back(v[x].second);
			else
				sortedVector.insert(sortedVector.begin() + binaryInsertionVector(sortedVector, v[x].second), v[x].second);
		}
		w = y;
		y += Jacob[i];
		if (y + Jacob[i] > v.size())
			y = v.size();
	}
}

void	PmergeMe::pairList(int ac, char **av)
{
	int	i;
	int	n1 = 0;

	n = ac - 1;
	for (i = 1; i <= n; i++)
	{
		n1 = atoi(av[i++]);
		if (i <= n)
			lst.push_back(makePair(n1, atoi(av[i])));
		else
			lst.push_back(makePair(-1, n1));
	}
	lst.sort();
}

void	PmergeMe::pushAList(std::list<std::pair<int, int> > &lst)
{
	std::list<std::pair<int, int> >::iterator	a;
	for (a = lst.begin(); a != lst.end(); a++)
	{
		if (a->first == -1)
			continue ;
		sortedList.push_back(a->first);
	}
}

std::list<int>::iterator	PmergeMe::binarySearchList(std::list<int> &lst, int b)
{
	std::list<int>::iterator	low = lst.begin();
	std::list<int>::iterator	high = lst.end();

	--high;
	while (low != high)
	{
		std::list<int>::iterator	mid = low;
		std::advance(mid, std::distance(low, high) / 2);
		if (b < *mid)
			high = mid;
		else
			low = ++mid;
	}
	return (low);
}

/* sortedList.insert(std::upper_bound(sortedList.begin(), sortedList.end(), it->second), it->second) */
void	PmergeMe::FordJohnsonList(void)
{
	pushAList(lst);

	int	x = 0;
	int	y = Jacob[2];
	int	w = 0;
	for (int i = 3; i < (int)Jacob.size() && y <= (int)lst.size(); i++)
	{
		for (x = y - 1; x >= w;)
		{
			std::list<int>::iterator last = sortedList.end();
			--last;
			std::list<std::pair<int, int> >::iterator it = lst.begin();
			std::advance(it, x);
			if (it->second < *last)
				sortedList.insert(binarySearchList(sortedList, it->second), it->second);
			else
				sortedList.push_back(it->second);
			x--;
		}
		w = y;
		y += Jacob[i];
		if (y >= (int)lst.size())
			y = lst.size();
	}
}

void	PmergeMe::output(int ac, char **av)
{
	std::cout << "Before:	";
	for (int i = 1; i < ac; i++)
	{
		std::cout << av[i];
		if (i + 1 != ac)
			std::cout << " ";
	}
	std::cout << "\n";
	std::cout << "After:	";
	printContainer(sortedVector);

	std::cout << "After:	";
	printContainer(sortedList);

	std::cout << "Time to process a range of " << ac - 1 << " elements with [";
	printFunctionName(sortedVector);
	std::cout << "] : " << " time " << "\n";

	std::cout << "Time to process a range of " << ac - 1 << " elements with [";
	printFunctionName(sortedList);
	std::cout << "] : " << " time " << "\n";
}

void	PmergeMe::FJsort(int ac, char **av)
{
	pairVector(ac, av);
	pairList(ac, av);
	FordJohnsonVector();
	FordJohnsonList();
	output(ac, av);
}