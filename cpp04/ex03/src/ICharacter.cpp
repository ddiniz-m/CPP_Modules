
#include "../inc/ICharacter.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
ICharacter::ICharacter()
{
	std::cout << GREEN << "ICharacter Default Constructor Called" << NC << std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter &copy_a)
{
	std::cout << GREEN << "ICharacter Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

ICharacter::ICharacter(const ICharacter &copy)
{
	std::cout << GREEN << "ICharacter Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

ICharacter::~ICharacter()
{
	std::cout << RED << "ICharacter Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------