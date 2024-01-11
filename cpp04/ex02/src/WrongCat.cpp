
#include "../inc/WrongCat.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
WrongCat::WrongCat()
{
	std::cout << GREEN << "WrongCat Default Constructor Called" << NC << std::endl;
	setType("Cat");
}

WrongCat& WrongCat::operator=(const WrongCat &copy_a)
{
	std::cout << GREEN << "WrongCat Copy Assignment Operator Called" << NC << std::endl;
	WrongAnimal::operator=(copy_a);
	return (*this);
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << GREEN << "WrongCat Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	WrongCat::makeSound(void)
{
	std::cout << getType() << " made a sound: Meow Meow" << std::endl;
}