#ifndef BASE_HPP
# define BASE_HPP

#define NC "\033[0m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"

#include <iostream>
#include <cstdlib>

class Base
{
	public:
		Base();
		virtual ~Base();

};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif

