
#include "../inc/Ice.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Ice::Ice()
{
	std::cout << GREEN << "Ice Default Constructor Called" << NC << std::endl;
}

Ice& Ice::operator=(const Ice &copy_a)
{
	std::cout << GREEN << "Ice Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

Ice::Ice(const Ice &copy)
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
	;
}

AMateria	*Ice::clone() const
{
	;
}