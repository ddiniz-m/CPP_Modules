
#include "../inc/AMateria.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
AMateria::AMateria()
{
	std::cout << GREEN << "AMateria Default Constructor Called" << NC << std::endl;
}

AMateria::AMateria(std::string const &_type)
{
	this->type = _type;
}

AMateria& AMateria::operator=(const AMateria &copy_a)
{
	std::cout << GREEN << "AMateria Copy Assignment Operator Called" << NC << std::endl;
	this->type = copy_a.type;
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
	return(this->type);
}

void	AMateria::setType(std::string const &type)
{
	this->type = type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "Default Use" << std::endl;
	(void)target;
}