#include "../inc/ClapTrap.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
ClapTrap::ClapTrap()
{
	std::cout << GREEN << "Default Constructor Called" << NC << std::endl;
	this->hp = 10;
	this->energy = 10;
	this->atk = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << GREEN << "Name Constructor Called" << NC << std::endl;
	this->name = name;
	this->hp = 10;
	this->energy = 10;
	this->atk= 0;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy_a)
{
	std::cout << GREEN << "Copy Assignment Operator Called" << NC << std::endl;
	this->atk = copy_a.atk;
	this->name = copy_a.name;
	this->energy = copy_a.energy;
	this->hp = copy_a.hp;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << GREEN << "Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

std::string	ClapTrap::getName(void)
{
	return(this->name);
}

int	ClapTrap::getHp(void)
{
	if (this->hp == 0)
		return (0);
	std::cout << "ClapTrap " << this->getName() << " has " << this->hp << " health points!" << std::endl;
	return(this->hp);
}

int	ClapTrap::getEnergy(void)
{
	std::cout << "ClapTrap " << this->getName() << " has " << this->energy << " energy points!" << std::endl;
	return (this->energy);
}

int ClapTrap::getAttack(void)
{
	return(this->atk);
}

void	ClapTrap::setAttack(unsigned int amount)
{
	if (energy <= 0)
	{
		std::cout << "Out of energy points!" << std::endl;
		return ;
	}
	this->atk = amount;
	std::cout << "ClapTrap " << this->getName() << " deals " << this->atk << " damage." << std::endl;
}

void	ClapTrap::setEnergy(unsigned int amount)
{
	this->energy = amount;
	std::cout << "ClapTrap " << this->getName() << "'s energy points were set to " << this->energy << std::endl;
}


int		ClapTrap::check(void)
{
	if (this->energy <= 0)
	{
		std::cout << this->getName() << " is out of energy points!" << std::endl;
		return (1);
	}
	if (this->hp <= 0)
			std::cout << this->getName() << " has no hp left!" << std::endl;
		return (1);
	return (0);
}

void ClapTrap::attack(const std::string& target)
{
	if (check())
		return ;
	std::cout << "ClapTrap " << this->getName() << " attacked " << target;
	std::cout << " dealing " << this->atk << " points of damage!" << std::endl;
	this->energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " took " << amount << " points of damage." << std::endl;
		this->hp -= amount;
	}
	if (this->hp <= 0)
	{
		this->hp = 0;
		this->atk = 0;
		std::cout << "ClapTrap " << this->getName() << " died!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (check())
		return ;
	if (amount + this->hp > 10)
		this->hp = 10;
	else
		this->hp += amount;
	this->energy--;
	std::cout << "ClapTrap " << this->getName() << " repaired " << amount << " health points" << std::endl;
}