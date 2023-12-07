
#include "../inc/ClapTrap.hpp"

int main()
{
	ClapTrap mc("Luffy");
	ClapTrap villain("Arlong");

	mc.setAttack(2);
	villain.setAttack(3);
	mc.getHp();
	villain.getHp();

	std::cout << std::endl;

	mc.attack(villain.getName());
	villain.takeDamage(mc.getAttack());
	villain.getHp();
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
	mc.setAttack(9);
	mc.attack(villain.getName());
	villain.takeDamage(mc.getAttack());
	villain.getHp();
	std::cout << std::endl;

	villain.attack(mc.getName());
	mc.takeDamage(villain.getAttack());
	mc.takeDamage(villain.getAttack());
	mc.getHp();
	std::cout << std::endl;

	mc.getEnergy();
	mc.setEnergy(0);
	mc.attack("Air");
}