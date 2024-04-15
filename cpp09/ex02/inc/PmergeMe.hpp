#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class PmergeMe
{
	private:
		
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe &copy_a);
		PmergeMe(const PmergeMe &copy);
};

#endif

