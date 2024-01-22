
#include "../inc/ScavTrap.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << GREEN << "ScavTrap Default Constructor Called" << NC << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->atk = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN << "ScavTrap Name Constructor Called" << NC << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->atk = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap()
{
	std::cout << GREEN << "ScavTrap Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy_a)
{
	std::cout << GREEN << "ScavTrap Copy Assignment Operator Called" << NC << std::endl;
	ClapTrap::operator=(copy_a);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void ScavTrap::attack(const std::string& target)
{
	if (check())
		return ;
	std::cout << "ScavTrap " << this->getName() << " attacked " << target;
	std::cout << " dealing " << this->atk << " points of damage!" << std::endl;
	this->energy--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << RED << "ScavTrap " << this->getName() << " is in Gate Keeper mode." << NC <<std::endl;
}