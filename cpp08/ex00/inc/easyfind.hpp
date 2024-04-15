#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T> int easyfind(T &container, const int i)
{
	typename T::iterator	it;

	it = find(container.begin(), container.end(), i);
	if (it != container.end())
		return (*it);
	throw std::runtime_error("Element not found!");
}

#endif