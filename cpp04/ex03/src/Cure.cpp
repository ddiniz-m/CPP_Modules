
#include "../inc/Cure.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Cure::Cure()
{
	std::cout << GREEN << "Cure Default Constructor Called" << NC << std::endl;
	this->type = "cure";
}

Cure& Cure::operator=(const Cure &copy_a)
{
	std::cout << GREEN << "Cure Copy Assignment Operator Called" << NC << std::endl;
	this->type = copy_a.type;
	return (*this);
}

Cure::Cure(const Cure &copy) : AMateria()
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
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	(void)target;
}

AMateria	*Cure::clone() const
{
	AMateria *clone = new Cure;
	return(clone);
}
