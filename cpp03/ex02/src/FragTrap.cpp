
#include "../inc/FragTrap.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << GREEN << "FragTrap Default Constructor Called" << NC << std::endl;
	this->setHp(100);
	this->setEnergy(100);
	this->setAttack(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN << "FragTrap Default Constructor Called" << NC << std::endl;
	this->setHp(100);
	this->setEnergy(100);
	this->setAttack(30);
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap()
{
	std::cout << GREEN << "FragTrap Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy_a)
{
	std::cout << GREEN << "FragTrap Copy Assignment Operator Called" << NC << std::endl;
	ClapTrap::operator=(copy_a);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void FragTrap::attack(const std::string& target)
{
	if (check())
		return ;
	std::cout << "FragTrap " << this->getName() << " attacked " << target << "!!" << std::endl;
	this->setEnergy(getEnergy(1) - 1);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << GREEN << "FragTrap " << this->getName() << " requested a High Five" << NC <<std::endl;
}