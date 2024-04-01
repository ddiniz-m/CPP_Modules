#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>

#define NC "[0m"
#define RED "[0;31m"
#define GREEN "[0;32m"
#define YELLOW "[0;33m"
#define MAGENTA "[0;35m"

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

