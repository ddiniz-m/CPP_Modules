
#include "../inc/Cat.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Cat::Cat()
{
	std::cout << GREEN << "Cat Default Constructor Called" << NC << std::endl;
	setType("Cat");
}

Cat& Cat::operator=(const Cat &copy_a)
{
	std::cout << GREEN << "Cat Copy Assignment Operator Called" << NC << std::endl;
	Animal::operator=(copy_a);
	return (*this);
}

Cat::Cat(const Cat &copy)
{
	std::cout << GREEN << "Cat Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << RED << "Cat Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	Cat::makeSound(void)
{
	std::cout << getType() << " made a sound: Meow Meow" << std::endl;
}