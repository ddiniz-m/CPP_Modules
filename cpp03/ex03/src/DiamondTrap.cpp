
#include "../inc/DiamondTrap.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << GREEN << "DiamondTrap Default Constructor Called" << NC << std::endl;
	this->setHp(ft.getHp());
	this->setEnergy(st.getEnergy());
	this->setAttack(ft.getAttack());
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << GREEN << "DiamondTrap Name Constructor Called" << NC << std::endl;
	this->name = name;
	this->setHp(ft.getHp());
	this->setEnergy(st.getEnergy());
	this->setAttack(ft.getAttack());
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &copy_a)
{
	std::cout << GREEN << "DiamondTrap Copy Assignment Operator Called" << NC << std::endl;
	this->name = copy_a.name;
	ClapTrap::operator=(copy_a);
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << GREEN << "DiamondTrap Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap Name is " << this->name << " and ClapTrap name is " << ClapTrap::getName() << std::endl;

}