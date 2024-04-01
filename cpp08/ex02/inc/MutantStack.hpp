#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <list>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"

template <typename T>
class myIterator;

//	public std::stack<T, std::deque<T> >
//MutantStack is inheriting from std::stack with value type "T" 
// and std::deque<T> as underlying container type
template <typename T>
class MutantStack : public std::stack <T, std::deque<T> >
{
	public:
		typedef typename std::deque<T>::iterator iterator;

		MutantStack();
		~MutantStack();
		MutantStack<T>& operator=(const MutantStack<T> &copy_a);
		MutantStack(const MutantStack<T> &copy);

		iterator begin(void);
		iterator end(void);
		size_t	size(void);
};


// ---------------------- Orthodox Canonical Form -----------------------------
template<typename T>
MutantStack<T>::MutantStack()
{
	std::cout << GREEN << "MutantStack Default Constructor Called" << NC << std::endl;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &copy_a)
{
	std::cout << GREEN << "MutantStack Copy Assignment Operator Called" << NC << std::endl;
	std::stack<T>::operator=(copy_a);
	return (*this);
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy), std::deque<T>(copy)
{
	std::cout << GREEN << "MutantStack Copy Constructor Called" << NC << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << RED << "MutantStack Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}

template<typename T>
size_t	MutantStack<T>::size(void)
{
	return (std::stack<T>::c.size());
}

#endif