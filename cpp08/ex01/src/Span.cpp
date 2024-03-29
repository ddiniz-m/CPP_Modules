
#include "../inc/Span.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Span::Span()
{
	std::cout << GREEN << "Span Default Constructor Called" << NC << std::endl;
}

Span& Span::operator=(const Span &copy_a)
{
	std::cout << GREEN << "Span Copy Assignment Operator Called" << NC << std::endl;
	v = copy_a.v;
	v.reserve(copy_a.v.capacity());

	std::cout << "capacity1: "<< v.capacity() << "\n";
	return (*this);
}

Span::Span(const Span &copy)
{
	std::cout << GREEN << "Span Copy Constructor Called" << NC << std::endl;
	v.reserve(copy.v.capacity());
	std::cout << "capacity2: "<< v.capacity() << "\n";
	*this = copy;
}

Span::~Span()
{
	std::cout << RED << "Span Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

Span::Span(const unsigned int N)
{
	std::cout << GREEN << "Span Size Constructor Called" << NC << std::endl;
	v.reserve(N);
}

void	Span::addNumber(int i)
{
	if (v.size() >= v.capacity())
		throw std::runtime_error("Array is full!");
	v.push_back(i);
}

void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	while (start < end)
		addNumber(*start++);
}

void	Span::shortestSpan(void)
{
	int	dif;
	int	res;

	if (v.size() < 2)
	{
		std::cout << "Impossible\n";
		return ;
	}

	std::vector<int> buf = v;
	sort(buf.begin(), buf.end());
	std::vector<int>::iterator it = buf.begin();

	res = *max_element(buf.begin(), buf.end());
	for (it = buf.begin(); it < buf.end() && it + 1 < buf.end(); it++)
	{
		dif = abs(*it - *(it + 1));
		if (dif < res)
			res = dif;
	}
	std::cout << "Shortest Span: " << res << "\n";
}

void	Span::longestSpan(void)
{
	if (v.size() < 2)
	{
		std::cout << "Impossible\n";
		return ;
	}
	std::cout << "Longest Span: " << *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()) << "\n";
}

std::vector<int>	&Span::getArray(void)
{
	return(this->v);
}

void	Span::vectorPrint(void)
{
	std::vector<int>::iterator it;
	std::cout << YELLOW << "Array:\n";
	for (it = v.begin(); it < v.end() - 1; it++)
		std::cout << *it << ", ";
	std::cout << *it << NC << "\n\n";
}