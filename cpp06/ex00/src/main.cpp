
#include "../inc/ScaleConverter.hpp"

int	main(int ac, char **av)
{
	ScaleConverter	Conv;

	Conv.Convert(av[1]);
	(void) ac;
}