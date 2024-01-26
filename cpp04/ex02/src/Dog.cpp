
#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Dog::Dog()
{
	std::cout <<  YELLOW << "Dog "<< GREEN << "Default Constructor Called" << NC << std::endl;
	setType("Dog");
	this->brain = new Brain();
}

Dog& Dog::operator=(const Dog &copy_a)
{
	std::cout << GREEN << "Dog Copy Assignment Operator Called" << NC << std::endl;
	AAnimal::operator=(copy_a);
	if (this->brain)
		delete(this->brain);
	this->type = copy_a.type;
	this->brain = new Brain(*copy_a.brain);
	return (*this);
}

Dog::Dog(const Dog &copy) : AAnimal()
{
	std::cout << GREEN << "Dog Copy Constructor Called" << NC << std::endl;
	this->brain = NULL;
	*this = copy;
}

Dog::~Dog()
{
	std::cout <<  YELLOW << "Dog "<< RED << "Destructor Called" << NC << std::endl;
	delete(brain);
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	Dog::makeSound(void) const
{
	std::cout << getType() << " made a sound: Woof Woof" << std::endl;
}

Brain *Dog::getBrain(void)
{
	return (this->brain);
}