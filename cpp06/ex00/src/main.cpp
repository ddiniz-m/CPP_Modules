
#include "../inc/ScaleConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Incorrect amount of arguments\n" << NC;
		std::cout << GREEN << "Usage: ./Converter <argument>\n" << NC;
		return (1);
	}

	ScaleConverter	Conv;

	Conv.Convert(av[1]);
}