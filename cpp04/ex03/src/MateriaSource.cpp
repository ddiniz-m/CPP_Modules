
#include "../inc/MateriaSource.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
MateriaSource::MateriaSource()
{
	std::cout << GREEN << "MateriaSource Default Constructor Called" << NC << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy_a)
{
	std::cout << GREEN << "MateriaSource Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << GREEN << "MateriaSource Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	std::cout << RED << "MateriaSource Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------