
#include "../inc/FragTrap.hpp"

int main()
{
	FragTrap mc("Luffy");
	FragTrap villain("Arlong");

	mc.getAttack();
	mc.getHp();
	mc.getEnergy(0);
	std::cout << std::endl;

	mc.attack(villain.getName());
	villain.takeDamage(mc.getAttack());
	villain.getHp();
	mc.highFivesGuys();
	std::cout << std::endl;

	villain.attack(mc.getName());
	mc.takeDamage(villain.getAttack());
	villain.attack(mc.getName());
	mc.takeDamage(villain.getAttack());
	mc.getHp();
	std::cout << std::endl;

	mc.beRepaired(4);
	mc.getHp();
	std::cout << std::endl;

	std::cout << mc.getName() << " got a power boost!"<< std::endl;
	mc.setAttack(200);
	mc.attack(villain.getName());
	villain.takeDamage(mc.getAttack());
	villain.getHp();
	mc.highFivesGuys();
	std::cout << std::endl;

	villain.attack(mc.getName());
	mc.takeDamage(villain.getAttack());
	mc.takeDamage(villain.getAttack());
	mc.getHp();
	std::cout << std::endl;

	mc.getEnergy(0);
	mc.setEnergy(0);
	mc.attack("Arlong");
}