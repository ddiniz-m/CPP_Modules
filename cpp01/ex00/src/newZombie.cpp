
#include "../inc/Zombie.hpp"

Zombie	*Zombie::newZombie(std::string name)
{
	Zombie	*newZombie;

	newZombie = new Zombie;
	newZombie->name = name;

	(*newZombie).announce();
	return (newZombie);
}