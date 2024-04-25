#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

template <typename T>
void	printFunctionName(T &)
{
	std::string	pretty = __PRETTY_FUNCTION__;
	pretty.erase(0 , pretty.find('=') + 2);
	pretty.erase(pretty.size() - 1);
	if (pretty.substr(3, 9) == "::__cxx11")
		pretty.erase(3, 9);
	std::cout << pretty;
}

template <typename T>
void	printContainer(T &container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

class PmergeMe
{
	private:

		int									n;
		std::clock_t						start;
		std::list<std::pair<int, int> >		lst;
		std::vector<std::pair<int, int> >	v;
		std::vector<u_int64_t>				Jacob;
		std::vector<int>					sortedVector;
		std::list<int>						sortedList;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe &copy_a);
		PmergeMe(const PmergeMe &copy);

		void						FJsort(int ac, char **av);
		std::pair<int, int>			makePair(int n1, int n2);

		void						pairVector(int ac, char **av);
		void						firstSortVector(int start);
		void						pushAVector(std::vector<std::pair<int, int> > &v);
		void						sequenceInitVector(void);
		void						FordJohnsonVector(void);

		void						pairList(int ac, char **av);
		void						firstSortList(int start);
		void						pushAList(std::list<std::pair<int, int> > &lst);
		std::list<int>::iterator	binarySearchList(std::list<int> &lst, int b);
		void						FordJohnsonList(void);

		void						output(int ac, char **av);
};
#endif
