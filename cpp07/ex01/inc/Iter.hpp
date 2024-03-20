#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T arr[], int len, F func)
{
	for (int i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>	void myPrint(const T& value)
{
	std::cout << value << "\n";
}

#endif