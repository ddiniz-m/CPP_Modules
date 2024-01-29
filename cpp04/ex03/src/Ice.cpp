
#include "../inc/Ice.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Ice::Ice()
{
	std::cout << GREEN << "Ice Default Constructor Called" << NC << std::endl;
	this->type = "ice";
}

Ice& Ice::operator=(const Ice &copy_a)
{
	std::cout << GREEN << "Ice Copy Assignment Operator Called" << NC << std::endl;
	this->type = copy_a.type;
	return (*this);
}

Ice::Ice(const Ice &copy) : AMateria()
{
	std::cout << GREEN << "Ice Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Ice::~Ice()
{
	std::cout << RED << "Ice Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void Ice::use(ICharacter& target)
{
	std::cout << " *shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria	*Ice::clone() const
{
	AMateria *clone = new Ice;
	return(clone);
}