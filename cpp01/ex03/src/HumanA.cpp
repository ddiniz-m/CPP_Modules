
#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weaponREF) : _weaponREF(weaponREF)
{
	std::cout << GREEN << "HumanA Object Created" << NC << std::endl;
	this->_name = name;
}

HumanA::~HumanA()
{
	std::cout << RED << "HumanA Object Destroyed" << NC << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weaponREF.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->_weaponREF = weapon;
}
