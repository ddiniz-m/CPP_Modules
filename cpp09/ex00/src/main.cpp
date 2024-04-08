#include "../inc/BitcoinExchange.hpp"

//map<key, value>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Incorrect amount of arguments.\n";
		return (1);
	}

	std::string				line;
	std::fstream			file;
	BitcoinExchange			bcn;

	bcn.readDb();

	file.open(av[1], std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file.\n";
		return (1);
	}

	while(!file.eof())
	{
		getline(file, line);
		bcn.fillMap(line);
	}
	bcn.printMap(bcn.getMap());
	std::cout << "\n\n";
	bcn.printMap(bcn.getDb());
	return (0);
}