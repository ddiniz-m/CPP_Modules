
#include "../inc/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << GREEN << name << "Object Created" << NC << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << name;
	if (!name.empty())
		std::cout << " ";
	std::cout << "Object Destroyed" << NC << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
