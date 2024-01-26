
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Cat::Cat()
{
	std::cout <<  MAGENTA << "Cat "<< GREEN << "Default Constructor Called" << NC << std::endl;
	setType("Cat");
	this->brain = new Brain();
}

Cat& Cat::operator=(const Cat &copy_a)
{
	std::cout << GREEN << "Cat Copy Assignment Operator Called" << NC << std::endl;
	AAnimal::operator=(copy_a);
	if (this->brain)
		delete(this->brain);
	this->type = copy_a.type;
	this->brain = new Brain(*copy_a.brain);
	return (*this);
}

Cat::Cat(const Cat &copy) : AAnimal()
{
	std::cout << GREEN << "Cat Copy Constructor Called" << NC << std::endl;
	this->brain = NULL;
	*this = copy;
}

Cat::~Cat()
{
	std::cout <<  MAGENTA << "Cat "<< RED << "Destructor Called" << NC << std::endl;
	delete(brain);
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	Cat::makeSound(void) const
{
	std::cout << getType() << " made a sound: Meow Meow" << std::endl;
}

Brain *Cat::getBrain(void)
{
	return (this->brain);
}