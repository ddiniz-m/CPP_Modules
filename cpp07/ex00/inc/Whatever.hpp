#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T> void swap(T &x, T &y)
{
	T z;

	z = x;
	x = y;
	y = z;
}

template <typename T> T min(T x ,T y)
{
	return ((x <= y) ? ((x < y) ? x : y) : y);
}

template <typename T> T max(T x, T y)
{
	return ((x >= y) ? ((x > y) ? x : y) : y);
}

#endif

//Ternary Operations
/*

condition ? value1 : value 2

if (condition)
	value1
else
	value2

condition1 ? (condition2 ? value1 : value2) : value3

if (condition1)
{
	if (condition2)
		value1
	else
		value2
}
else
	value3
*/