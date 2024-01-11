
#include "../inc/Character.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Character::Character()
{
	std::cout << GREEN << "Character Default Constructor Called" << NC << std::endl;
}

Character& Character::operator=(const Character &copy_a)
{
	std::cout << GREEN << "Character Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
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

std::string const &Character::getName() const
{
	;
}

void	Character::equip(AMateria* m)
{
	;
}

void	Character::unequip(int idx)
{
	;
}

void	Character::use(int idx, ICharacter& target)
{
	;
}