
#include "../inc/AAnimal.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
AAnimal::AAnimal()
{
	std::cout << GREEN << "AAnimal Default Constructor Called" << NC << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &copy_a)
{
	std::cout << GREEN << "AAnimal Copy Assignment Operator Called" << NC << std::endl;
	this->type = copy_a.type;
	return (*this);
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << GREEN << "AAnimal Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

std::string	AAnimal::getType(void) const
{
	return(this->type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Standard AAnimal Noise" << std::endl;
}

void	AAnimal::setType(std::string name)
{
	this->type = name;
}