
#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type)
{
	std::cout << GREEN << "Weapon Object Created" << NC << std::endl;
	this->_type = type;
}

Weapon::~Weapon()
{
	std::cout << RED << "Weapon Object Destroyed" << NC << std::endl;
}

const std::string	&Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}