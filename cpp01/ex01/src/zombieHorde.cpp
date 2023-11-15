
#include "../inc/Zombie.hpp"

Zombie	*Zombie::zombieHorde(int N, std::string name)
{
	int	i;
	Zombie	*pZombie;

	pZombie = new Zombie[N];

	i = 0;
	while (i < N)
	{
		pZombie[i].name = name;
		pZombie[i].announce();
		i++;
	}
	return (pZombie);
} 