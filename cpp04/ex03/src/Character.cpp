
#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Character::Character()
{
	std::cout << GREEN << "Character Default Constructor Called" << NC << std::endl;
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
}
// ---------------------- Orthodox Canonical Form -----------------------------

Character::Character(std::string name)
{
	std::cout << GREEN << "Character Name Constructor Called" << NC << std::endl;
	this->name = name;
}

std::string const &Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	static int index = 0;

	inventory[index] = m;
	std::cout << "Equiped " << m->getType() << " in slot " << index << std::endl;
	index++;
	if (index == 3)
		index = 0;
}

void	Character::unequip(int idx)
{
	std::cout << "Unequiped " << inventory[idx]->getType() << " slot number " << idx << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	inventory[idx]->use(target);
}
