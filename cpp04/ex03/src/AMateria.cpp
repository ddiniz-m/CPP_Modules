
#include "../inc/AMateria.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
AMateria::AMateria()
{
	std::cout << GREEN << "AMateria Default Constructor Called" << NC << std::endl;
}

AMateria::AMateria(std::string const &_type)
{
	setType(type);
}

AMateria& AMateria::operator=(const AMateria &copy_a)
{
	std::cout << GREEN << "AMateria Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << GREEN << "AMateria Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

std::string const &AMateria::getType() const
{
	;
}

void	AMateria::setType(std::string const &type)
{
	;
}