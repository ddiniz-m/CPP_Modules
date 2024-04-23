#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <cstdlib>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class PmergeMe
{
	private:
		int									n;
		std::list<int>						lst;
		std::vector<std::pair<int, int> >	v;
		std::vector<int>					sorted;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe &copy_a);
		PmergeMe(const PmergeMe &copy);

		void				pairVector(int ac, char **av);
		std::pair<int, int>	makePair(int n1, int n2);
		void				firstSort(int start);
		int					binaryInsertion(std::vector<int> iter, int b);
		void				pushA(void);
		void				FordJohnson(void);
};

#endif

