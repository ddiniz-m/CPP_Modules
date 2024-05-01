#include "../inc/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Incorrect amount of arguments.\n";
		return (1);
	}

	BitcoinExchange	btc;

	btc.readDb();
	btc.readInput(av);
	return (0);
}