
#include "../inc/WrongAnimal.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal Default Constructor Called" << NC << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy_a)
{
	std::cout << GREEN << "WrongAnimal Copy Assignment Operator Called" << NC << std::endl;
	this->type = copy_a.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << GREEN << "WrongAnimal Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

std::string	WrongAnimal::getType(void) const
{
	return(this->type);
}

void	WrongAnimal::setType(std::string name)
{
	this->type = name;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong Standard Animal Noise" << std::endl;
}