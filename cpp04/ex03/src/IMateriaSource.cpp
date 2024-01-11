
#include "../inc/IMateriaSource.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
IMateriaSource::IMateriaSource()
{
	std::cout << GREEN << "IMateriaSource Default Constructor Called" << NC << std::endl;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource &copy_a)
{
	std::cout << GREEN << "IMateriaSource Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

IMateriaSource::IMateriaSource(const IMateriaSource &copy)
{
	std::cout << GREEN << "IMateriaSource Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

IMateriaSource::~IMateriaSource()
{
	std::cout << RED << "IMateriaSource Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------