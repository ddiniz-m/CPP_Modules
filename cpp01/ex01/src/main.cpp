
#include "../inc/Zombie.hpp"

int	main(void)
{
	Zombie	zombie;
	Zombie	*pZombie;

	pZombie = zombie.zombieHorde(5, "HORDE");
	delete[] pZombie;
	pZombie = zombie.zombieHorde(10, "TSUNAMI");
	delete[] pZombie;
}