#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

template <typename T>
class Array
{
	private:
		unsigned int	len;
		T	*arr;
	public:
		Array();
		~Array();
		Array<T>& operator=(const Array<T> &copy_a);
		Array(const Array<T> &copy);

		Array(unsigned int n);

		void	myPrint(void);

		int	size(void);

		T& operator[](unsigned int element);

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

// ---------------------- Orthodox Canonical Form -----------------------------
template<typename T>
Array<T>::Array()
{
	this->arr = new T[0];
	this->len = 0;
	std::cout << GREEN << "Array Default Constructor Called" << NC << std::endl;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &copy_a)
{
	std::cout << GREEN << "Array Copy Assignment Operator Called" << NC << std::endl;

	if (this->arr)
		delete[] this->arr;
	len = copy_a.len;
	arr = new T[len];
	for (unsigned int i = 0; i < len; i++)
		arr[i] = copy_a.arr[i];
	return (*this);
}

template<typename T>
Array<T>::Array(const Array<T> &copy)
{
	std::cout << GREEN << "Array Copy Constructor Called" << NC << std::endl;
	this->arr = NULL;
	*this = copy;
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->arr;
	std::cout << RED << "Array Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

template<typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << GREEN << "Array Size Constructor Called" << NC << std::endl;
	this->arr = new T[n];
	this->len = n;
/* 	for (int i = 0; i < this->len; i++)
	{
		this->arr[i] = new T();
	} */
}

template<typename T>
int	Array<T>::size(void)
{
	int	count = 0;

	for (unsigned int i = 0; i < this->len; i++)
		count++;
	return (count);
}

template <typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Out of Bounds\n");
}

template <typename T>
T& Array<T>::operator[](unsigned int element)
{
	if (element < 0 || element >= len)
		throw OutOfBoundsException();
	return (this->arr[element]);
}

template <typename T>
void	Array<T>::myPrint(void)
{
	for (unsigned int i = 0; i < this->len; i++)
		std::cout << this->arr[i] << "\n";
}

#endif

