
#include "../inc/Cat.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Cat::Cat()
{
	std::cout << GREEN << "Cat Default Constructor Called" << NC << std::endl;
	this->type = "Cat";
}

Cat& Cat::operator=(const Cat &copy_a)
{
	std::cout << GREEN << "Cat Copy Assignment Operator Called" << NC << std::endl;
	Animal::operator=(copy_a);
	return (*this);
}

Cat::Cat(const Cat &copy) : Animal()
{
	std::cout << GREEN << "Cat Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << RED << "Cat Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	Cat::makeSound(void) const
{
	std::cout << this->type << " made a sound: Meow Meow" << std::endl;
}