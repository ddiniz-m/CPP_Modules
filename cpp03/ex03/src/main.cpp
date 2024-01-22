
#include "../inc/DiamondTrap.hpp"

int main()
{
	DiamondTrap mc("Luffy");
	DiamondTrap villain("Arlong");

	std::cout << "DiamondTrap " << mc.getName() << " has " << mc.getHp() << " health points!" << std::endl;
	std::cout << "DiamondTrap " << mc.getName() << " has " << mc.getEnergy() << " energy points!" << std::endl;
	std::cout << "DiamondTrap " << mc.getName() << " has " << mc.getAttack() << " attack points!" << std::endl;
	std::cout << std::endl;

	mc.attack(villain.getName());
	villain.takeDamage(mc.getAttack());
	std::cout << std::endl;

	villain.attack(mc.getName());
	mc.takeDamage(villain.getAttack());
	villain.attack(mc.getName());
	mc.takeDamage(villain.getAttack());
	std::cout << std::endl;

	std::cout << "DiamondTrap " << mc.getName() << " has " << mc.getHp() << " health points!" << std::endl;

	mc.guardGate();
	mc.whoAmI();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}