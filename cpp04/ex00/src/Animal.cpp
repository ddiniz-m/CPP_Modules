
#include "../inc/Animal.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Animal::Animal()
{
	std::cout << GREEN << "Animal Default Constructor Called" << NC << std::endl;
}

Animal& Animal::operator=(const Animal &copy_a)
{
	std::cout << GREEN << "Animal Copy Assignment Operator Called" << NC << std::endl;

	return (*this);
}

Animal::Animal(const Animal &copy)
{
	std::cout << GREEN << "Animal Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << RED << "Animal Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

std::string	Animal::getType(void) const
{
	return(this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "test" << std::endl;
}

void	Animal::setType(std::string name)
{
	this->type = name;
}