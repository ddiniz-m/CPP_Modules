
#include "../inc/Cure.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Cure::Cure()
{
	std::cout << GREEN << "Cure Default Constructor Called" << NC << std::endl;
}

Cure& Cure::operator=(const Cure &copy_a)
{
	std::cout << GREEN << "Cure Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

Cure::Cure(const Cure &copy)
{
	std::cout << GREEN << "Cure Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Cure::~Cure()
{
	std::cout << RED << "Cure Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void Cure::use(ICharacter& target)
{
	;
}

AMateria	*Cure::clone() const
{
	;
}
