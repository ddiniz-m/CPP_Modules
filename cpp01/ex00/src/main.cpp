
#include "../inc/Zombie.hpp"

int	main(void)
{
	Zombie	zombie;
	Zombie	*pZombie;

	pZombie = zombie.newZombie("NEW_ZOMBIE");
	zombie.randomChump("RANDOM_CHUMP");

	delete pZombie;
}