
#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << GREEN << "HumanB Object Created" << NC << std::endl;
	this->_name = name;
}

HumanB::~HumanB()
{
	std::cout << RED << "HumanB Object Destroyed" << NC << std::endl;
}

void	HumanB::attack()
{

	if (!_weapon)
		std::cout << this->_name << " has no weapon set!" << std::endl;
	else
	{
		/* const std::string &test = _weapon->getType(); */
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}