
#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Character::Character()
{
	std::cout << GREEN << "Character Default Constructor Called" << NC << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character& Character::operator=(const Character &copy_a)
{
	std::cout << GREEN << "Character Copy Assignment Operator Called" << NC << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = copy_a.inventory[i];
	this->name = copy_a.name;
	return (*this);
}

Character::Character(const Character &copy)
{
	std::cout << GREEN << "Character Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Character::~Character()
{
	std::cout << RED << "Character Destructor Called" << NC << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete(this->inventory[i]);
		this->inventory[i] = NULL;
	}
	
}
// ---------------------- Orthodox Canonical Form -----------------------------

Character::Character(std::string name)
{
	std::cout << GREEN << "Character Name Constructor Called" << NC << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

std::string const &Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Invalid Materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			continue ;
		else
		{
			inventory[i] = m;
			std::cout << "Equiped " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	if (!inventory[idx])
	{
		std::cout << "Empty Slot" << std::endl;
		return ;
	}
	std::cout << "Unequiped " << inventory[idx]->getType() << " in slot " << idx << std::endl;
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	if (!inventory[idx])
	{
		std::cout << "Empty Slot" << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}
