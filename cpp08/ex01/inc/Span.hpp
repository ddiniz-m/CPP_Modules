#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class Span
{
	private:
		std::vector<int> v;
	public:
		Span();
		~Span();
		Span& operator=(const Span &copy_a);
		Span(const Span &copy);

		Span(unsigned const int i);
		std::vector<int>	&getArray(void);
		void	addNumber(int i);
		void	shortestSpan(void);
		void	longestSpan(void);
		void	vectorPrint(void);
		void	addRange(std::vector<int>::iterator, std::vector<int>::iterator);
};

#endif

