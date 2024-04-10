
#include "../inc/Base.hpp"

Base::Base()
{
	std::cout << GREEN << "Base Constructor Called" << NC << std::endl;
}

Base::~Base()
{
	std::cout << RED << "Base Destructor Called" << NC << std::endl;
}
