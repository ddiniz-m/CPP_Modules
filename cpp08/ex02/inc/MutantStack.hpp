#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &copy_a);
		MutantStack<T>::MutantStack(const MutantStack<T> &copy);

		typedef typename std::stack<T>::iterator _iterator;
		void	begin(void);
		void	end(void);
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
	return (*this);
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy)
{
	std::cout << GREEN << "MutantStack Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << RED << "MutantStack Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

template<typename T>
void	MutantStack<T>::begin()
{
	;
}

template<typename T>
void	MutantStack<T>::end()
{
	;
}

#endif