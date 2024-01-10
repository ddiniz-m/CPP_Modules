
#include "../inc/Dog.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Dog::Dog()
{
	std::cout << GREEN << "Dog Default Constructor Called" << NC << std::endl;
	setType("Dog");
}

Dog& Dog::operator=(const Dog &copy_a)
{
	std::cout << GREEN << "Dog Copy Assignment Operator Called" << NC << std::endl;
	Animal::operator=(copy_a);
	return (*this);
}

Dog::Dog(const Dog &copy)
{
	std::cout << GREEN << "Dog Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << RED << "Dog Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	Dog::makeSound(void)
{
	std::cout << getType() << " made a sound: Woof Woof" << std::endl;
}