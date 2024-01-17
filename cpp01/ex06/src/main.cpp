
#include "../inc/Harl.hpp"

int	main(int ac, char **av)
{
	Harl	object;
	if (ac != 2)
	{
		std::cout << "Incorrect number of arguments!" << std::endl;
		return (1);
	}
	object.complain(av[1]);
}